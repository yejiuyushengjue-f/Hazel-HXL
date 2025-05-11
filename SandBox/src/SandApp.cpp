#include <iostream>
#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {
	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event.ToString());
	}
};

class SandBox : public Hazel::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{

	}
	
	// 在此处实现应用层各种功能
};

// 客户端
Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox;
}