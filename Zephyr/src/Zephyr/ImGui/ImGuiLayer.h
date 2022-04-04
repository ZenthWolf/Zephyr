#pragma once
#include "Zephyr/Layer.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

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
		bool OnKeyPress(KeyPress& e);
		bool OnKeyRelease(KeyRelease& e);
		bool OnMouseMove(MouseMove& e);
		bool OnMousePress(MouseButtonPress& e);
		bool OnMouseRelease(MouseButtonRelease& e);
		bool OnMouseScroll(MouseScroll& e);

		float time = 0.0f;
	};
}
