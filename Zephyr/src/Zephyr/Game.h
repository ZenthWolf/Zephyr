#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Zephyr
{
	class ZEPHYR_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();
	};

	//CLIENT to define
	Game* LoadGame();

}
