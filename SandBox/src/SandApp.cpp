#include <iostream>
#include <Hazel.h>

class SandBox : public Hazel::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
	
	// 在此处实现应用层各种功能
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox;
}