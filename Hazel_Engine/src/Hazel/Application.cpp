#include "hzpch.h"
#include "Application.h"

#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());	// 显式地使用 std::unique_ptr 的构造函数以进行类型转换
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}

	Application* CreateApplication()
	{
		return nullptr;
	}
}