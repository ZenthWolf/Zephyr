#include "ZephyrPCH.h"

#include "Game.h"
#include "MainWindow.h"

#include <GLFW/glfw3.h>

namespace Zephyr
{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Game::Game()
	{
		window = std::unique_ptr<Window>(Window::Create());
		//Direct Events to be handled by OnEvent
		window->SetEventCallback(BIND_EVENT_FN(Game::OnEvent));
	}

	Game::~Game()
	{
	}

	void Game::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClose>(BIND_EVENT_FN(Game::OnWindowClose));

		ZW_ENGINE_INFO(e);
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

	bool Game::OnWindowClose(WindowClose& e)
	{
		running = false;
		return true;
	}
}
