#pragma once
#include <sstream>

#include "Event.h"
#include "Vec2.h"

namespace Zephyr
{
	class ZEPHYR_API WindowResize : public Event
	{
	public:
		WindowResize(Vec2<unsigned int> windowSize)
			: size(windowSize) {}

		inline Vec2<unsigned int> GetSize() const { return size; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << size.X << ", " << size.Y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	private:
		Vec2<unsigned int> size;
	};

	class ZEPHYR_API WindowClose : public Event
	{
	public:
		WindowClose() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};

	class ZEPHYR_API AppTick : public Event
	{
	public:
		AppTick() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};

	class ZEPHYR_API AppUpdate : public Event
	{
	public:
		AppUpdate() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};

	class ZEPHYR_API AppRender : public Event
	{
	public:
		AppRender() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};
}