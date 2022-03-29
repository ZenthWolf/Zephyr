#include "ZephyrPCH.h"

#include "Game.h"
#include "Log.h"
#include "MainWindow.h"

namespace Zephyr
{
	Game::Game()
	{
	}

	Game::~Game()
	{
	}

	void Game::Run()
	{
		auto eW = WindowResize(Vec2<unsigned int>(1920, 1080));

		ZW_TRACE(eW);
		while (true);
	}
}
