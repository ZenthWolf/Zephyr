#pragma once

#include "Layer.h"

namespace Zephyr
{
	class ZEPHYR_API LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin()
		{
			return layers.begin();
		}

		std::vector<Layer*>::iterator insert()
		{
			return layers.begin() + layerInsertIndex;
		}

		std::vector<Layer*>::iterator end()
		{
			return layers.end();
		}

	protected:
		std::vector<Layer*> layers;
		unsigned int layerInsertIndex = 0;
	};
}
