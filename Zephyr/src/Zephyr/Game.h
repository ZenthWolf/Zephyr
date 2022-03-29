#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Zephyr
{
	class ZEPHYR_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();
	private:
		std::unique_ptr<Window> window;
		bool running = true;
	};

	//CLIENT to define
	Game* LoadGame();

}
