#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "LayerStack.h"
#include "Window.h"

namespace Zephyr
{
	class ZEPHYR_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);


	private:
		bool OnWindowClose(WindowClose& e);

		std::unique_ptr<Window> window;
		bool running = true;
		LayerStack layerStack;
	};

	//CLIENT to define
	Game* LoadGame();

}
