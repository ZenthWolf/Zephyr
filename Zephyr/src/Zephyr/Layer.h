#pragma once

#include "Core.h"

#include "Events/Event.h"

namespace Zephyr
{
	class ZEPHYR_API Layer
	{
	public:
		Layer(std::string name);
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};

		inline const std::string& GetName() const { return debugName; }
	private:
		std::string debugName;
	};
}