#pragma once

#include "ZephyrPCH.h"
#include "Core.h"

namespace Zephyr
{
	enum class EventType
	{
		Invalid = -1,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPress, KeyRelease, KeyType,
		MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
	};

	enum EventCategory
	{
		None = 0,
		ApplicationCategory = BIT(0),
		InputCategory =       BIT(1),
		KeyboardCategory =    BIT(2),
		MouseCategory =       BIT(3),
		MouseButtonCategory = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class ZEPHYR_API Event
	{
	public:
		bool handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: eventOut(event)
		{
		}

		//Event processing calls with function to process event
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (eventOut.GetEventType() == T::GetStaticType())
			{
				eventOut.handled = func(*(T*)&eventOut);
				return true;
			}
			return false;
		}
	private:
		Event& eventOut;
	};

	//Allow events to be processed in spdlog
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}