#include "ZephyrPCH.h"

#include "Keyboard.h"

namespace Zephyr
{
	bool Keyboard::KeyIsPressed(unsigned char keycode) const
	{
		return keystate[keycode];
	}

	std::shared_ptr<Event> Keyboard::ReadKey()
	{
		std::shared_ptr<Event> keyevent;
		if (!keybuffer.empty())
		{
			keyevent = keybuffer.front();
			keybuffer.pop();
		}

		return keyevent;
	}

	char Keyboard::ReadChar()
	{
		if (!charbuffer.empty())
		{
			char charcode = charbuffer.front();
			charbuffer.pop();
			return charcode;
		}

		return 0;
	}

	bool Keyboard::KeyIsEmpty() const
	{
		return keybuffer.empty();
	}

	bool Keyboard::CharIsEmpty() const
	{
		return charbuffer.empty();
	}

	void Keyboard::FlushKey()
	{
		keybuffer = std::queue<std::shared_ptr<Event>>();
	}

	void Keyboard::FlushChar()
	{
		charbuffer = std::queue<char>();
	}

	void Keyboard::Flush()
	{
		FlushKey();
		FlushChar();
	}

	void Keyboard::OnKeyPressed(unsigned char keycode, int repeatCount)
	{
		keystate[keycode] = true;
		keybuffer.push(std::make_shared<KeyPress>(keycode,repeatCount));
		TrimBuffer(keybuffer);
	}

	void Keyboard::OnKeyReleased(unsigned char keycode)
	{
		keystate[keycode] = false;
		keybuffer.push(std::make_shared<KeyRelease>(keycode));
		TrimBuffer(keybuffer);
	}

	void Keyboard::OnChar(char character)
	{
		charbuffer.push(character);
		TrimBuffer(charbuffer);
	}

	template<typename T>
	void Keyboard::TrimBuffer(std::queue<T>& buffer)
	{
		while (buffer.size() > bufferSize)
			buffer.pop();
	}
}