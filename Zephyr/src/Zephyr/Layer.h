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

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Event& e) = 0;

		inline const std::string& GetName() const { return debugName; }
	private:
		std::string debugName;
	};
}