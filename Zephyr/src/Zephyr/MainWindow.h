#pragma once

#include "Core.h"

#include "Events/ApplicationEvents.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace Zephyr
{
	class ZEPHYR_API MainWindow
	{
	public:
		MainWindow() = default;
		MainWindow(const MainWindow&) = delete;
		MainWindow& operator=(const MainWindow&) = delete;

		Keyboard kbd;
		Mouse mouse;

		Vec2<unsigned int> GetWindowSize() const;
		std::shared_ptr<Event> ReadEvent();
		void Flush();

	private:

		void OnWindowClose();
		void OnWindowResize(Vec2<unsigned int> newSize);
		void OnAppTick();
		void OnAppUpdate();
		void OnAppRender();
		void TrimBuffer();

		Vec2<unsigned int> windowSize = { 800,600 };
		static constexpr unsigned int bufferSize = 4u;
		std::queue<std::shared_ptr<Event>> buffer;
	};
}
