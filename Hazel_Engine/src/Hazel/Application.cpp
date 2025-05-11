#include "hzpch.h"
#include "Application.h"

#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());	// 显式地使用 std::unique_ptr 的构造函数以进行类型转换
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));	// std::bind创建一个可调用对象，并将函数与该对象进行绑定
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatcher<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		HZ_CORE_TRACE("{0}", e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.GetHandled())
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlayer(Layer* layer)
	{
		m_LayerStack.PushOverlayer(layer);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	Application* CreateApplication()
	{
		return nullptr;
	}
}