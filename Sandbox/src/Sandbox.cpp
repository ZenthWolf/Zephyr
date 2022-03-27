#include <Zephyr.h>

class Sandbox : public Zephyr::Game
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Zephyr::Game* Zephyr::LoadGame()
{
	return new Sandbox();
}