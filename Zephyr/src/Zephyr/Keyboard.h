#pragma once

#include <bitset>
#include <queue>

#include "Core.h"
#include "Events/KeyEvent.h"

namespace Zephyr
{
	class ZEPHYR_API Keyboard
	{
		//friend class MainWindow;
	public:
		Keyboard() = default;
		Keyboard(const Keyboard&) = delete;
		Keyboard& operator=(const Keyboard&) = delete;

		bool KeyIsPressed(unsigned char keycode) const;
		
		std::shared_ptr<Event> ReadKey();
		char ReadChar();
		
		bool KeyIsEmpty() const;
		bool CharIsEmpty() const;
		
		void FlushKey();
		void FlushChar();
		void Flush();

	private:
		void OnKeyPressed(unsigned char keycode, int repeatCount);
		void OnKeyReleased(unsigned char keycode);
		void OnChar(char character);
		template<typename T>
		void TrimBuffer(std::queue<T>& buffer);

		static constexpr unsigned int nKeys = 256u;
		static constexpr unsigned int bufferSize = 4u;
		std::bitset<nKeys> keystate;
		std::queue<std::shared_ptr<Event>> keybuffer;
		std::queue<char> charbuffer;
	};
}
