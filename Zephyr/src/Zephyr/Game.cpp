#include "ZephyrPCH.h"

#include "Game.h"
#include "MainWindow.h"

#include <GLFW/glfw3.h>

namespace Zephyr
{
	Game::Game()
	{
		window = std::unique_ptr<Window>(Window::Create());
	}

	Game::~Game()
	{
	}

	void Game::Run()
	{
		auto eW = WindowResize(Vec2<unsigned int>(1920, 1080));

		ZW_TRACE(eW);
		while (running)
		{
			glClearColor(.2f, .2f, .24f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			window->OnUpdate();
		}
	}
}
