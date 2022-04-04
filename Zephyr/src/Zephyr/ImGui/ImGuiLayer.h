#pragma once
#include "Zephyr/Layer.h"

namespace Zephyr
{
	class ZEPHYR_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:
		float time = 0.0f;
	};
}
