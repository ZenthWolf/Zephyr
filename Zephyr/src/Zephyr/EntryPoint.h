#pragma once
#include "../Zephyr.h"

#ifdef ZW_WINDOWS_PLATFORM

extern Zephyr::Game* Zephyr::LoadGame();

int main(int argc, char** argv)
{
	Zephyr::Log::Init();
	ZW_ENGINE_WARN("Initialized Logger!");
	float someInfo = 2.7182818f;
	ZW_INFO("The C.L.I.E.N.T. sends their regards. {0}", someInfo);

	printf("A black wind begins to blow. . .\n");
	Zephyr::Game* game = Zephyr::LoadGame();
	game->Run();
	delete game;
}
#endif
 