#include <Zephyr.h>

class DebugLayer : public Zephyr::Layer
{
public:
	DebugLayer()
		:Layer("Debug") {}

	~DebugLayer() override
	{}

	void OnAttach() override
	{
		ZW_INFO("Layer {0} successfully attached.", GetName());
	};

	virtual void OnDetach()
	{
		ZW_INFO("Layer {0} successfully detached.", GetName());
	};

	virtual void OnUpdate()
	{

	};

	virtual void OnEvent(Zephyr::Event& e)
	{
		ZW_TRACE("Layer {0} event: {1}", GetName(), e);
	};
};

class Sandbox : public Zephyr::Game
{
public:
	Sandbox()
	{
		PushLayer(new DebugLayer());
	}

	~Sandbox()
	{

	}

};

Zephyr::Game* Zephyr::LoadGame()
{
	return new Sandbox();
}