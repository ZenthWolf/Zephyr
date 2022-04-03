
#include "ZephyrPCH.h"

#include "LayerStack.h"

namespace Zephyr
{
	LayerStack::~LayerStack()
	{
		for (Layer* l : layers)
			delete l;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		layers.emplace(layers.begin() + layerInsertIndex, layer);
		++layerInsertIndex;
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(layers.begin(), layers.begin()+layerInsertIndex, layer);

		if (it != layers.begin() + layerInsertIndex)
		{
			layers.erase(it);
			--layerInsertIndex;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(layers.begin() + layerInsertIndex, layers.end(), overlay);

		if (it != layers.end())
			layers.erase(it);
	}
}
