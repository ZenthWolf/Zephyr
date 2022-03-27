#pragma once

#include "Core.h"

namespace Zephyr
{
	class ZW_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();
	};

	//CLIENT to define
	Game* LoadGame();

}
