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
	
	// �ڴ˴�ʵ��Ӧ�ò���ֹ���
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox;
}