#pragma once
#include "Zephyr/Layer.h"

//Need Zephyr/ for client?
#include "Zephyr/Events/ApplicationEvent.h"
#include "Zephyr/Events/KeyEvent.h"
#include "Zephyr/Events/MouseEvent.h"

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
		bool OnKeyType(KeyType& e);
		bool OnKeyPress(KeyPress& e);
		bool OnKeyRelease(KeyRelease& e);
		bool OnMouseMove(MouseMove& e);
		bool OnMouseButtonPress(MouseButtonPress& e);
		bool OnMouseButtonRelease(MouseButtonRelease& e);
		bool OnMouseScroll(MouseScroll& e);
		bool OnWindowResize(WindowResize& e);

		float time = 0.0f;
	};
}
