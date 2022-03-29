#pragma once
#include "Event.h"

namespace Zephyr
{
	class ZEPHYR_API KeyEvent : public Event
	{
	public:
		inline char GetKeyCode() const
		{
			return keycode;
		}

		EVENT_CLASS_CATEGORY(InputCategory | KeyboardCategory)

	protected:
		KeyEvent()
			:keycode(-1) {}

		KeyEvent(char key)
			:keycode(key) {}

		const char keycode;
	};

	class ZEPHYR_API KeyPress : public KeyEvent
	{
	public:
		KeyPress()
			:count(-1) {}

		KeyPress(char key, int count)
			:KeyEvent(key), count(count) {}


		int GetRepeatCound() const
		{
			return count;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keycode << " (" << count << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPress)
		
	private:
		const int count;
	};

	class ZEPHYR_API KeyRelease : public KeyEvent
	{
	public:
		KeyRelease()
		{}

		KeyRelease(char key)
			:KeyEvent(key) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " <<keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRelease)
	};

}