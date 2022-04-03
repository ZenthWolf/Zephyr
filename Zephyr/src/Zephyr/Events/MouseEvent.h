#pragma once

#include "Event.h"
#include "Vec2.h"

namespace Zephyr
{
	class ZEPHYR_API MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(InputCategory | MouseCategory)
	};

	class ZEPHYR_API MouseMove : public MouseEvent
	{
	public:
		MouseMove(Vec2<float> pos)
			:pos(pos) {}

		inline Vec2<float> GetPos() const
		{
			return pos;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent: (" << GetPos().X << ", " << GetPos().Y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMove)
	protected:
		const Vec2<float> pos;
	};

	class ZEPHYR_API MouseScroll : public MouseEvent
	{
	public:
		MouseScroll(Vec2<float> scroll)
			:scroll(scroll) {}

		inline Vec2<float> GetScroll() const
		{
			return scroll;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: (" << GetScroll().X << ", " << GetScroll().Y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScroll)
	private:
		const Vec2<float> scroll;
	};

	class ZEPHYR_API MouseButtonEvent : public MouseEvent
	{
	public:
		inline int GetMouseButton() const
		{
			return button;
		}
	protected:
		MouseButtonEvent(int button)
			:button(button)
		{}

		int button;
	};

	class ZEPHYR_API MouseButtonPress : public MouseButtonEvent
	{
	public:
		MouseButtonPress(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPress)
	};

	class ZEPHYR_API MouseButtonRelease : public MouseButtonEvent
	{
	public:
		MouseButtonRelease(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonRelease)
	};
}