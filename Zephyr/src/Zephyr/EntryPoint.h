#pragma once
#include "../Zephyr.h"

#ifdef ZW_WINDOWS_PLATFORM

extern Zephyr::Game* Zephyr::LoadGame();

int main(int argc, char** argv)
{
	printf("A black wind begins to blow. . .\n");
	Zephyr::Game* game = Zephyr::LoadGame();
	game->Run();
	delete game;
}
#endif
 