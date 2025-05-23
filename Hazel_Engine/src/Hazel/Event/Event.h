#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"

namespace Hazel {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse 		 = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type)          \
    static EventType GetStaticType() {         \
        return EventType::type;          \
    }                                          \
    virtual EventType GetEventType() const override { \
        return GetStaticType();                \
    }                                          \
    virtual const char* GetName() const override { \
        return #type;                    \
    };

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event		// 所有事件的基类
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
		
		inline bool GetHandled() { return m_Handled; }
	protected:
		friend class EventDispatcher;		//声明为友元类后，即可在该类中访问 protected 中的内容

		bool m_Handled = false;
	};

	class EventDispatcher		// 基于事件的类型调度事件
	{
		template<typename T>
		using EventFu = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event) {
		}

		template<typename T>
		bool Dispatcher(EventFu<T> func)	// 利用模板 T 实现类型的检验
		{
			if (m_Event.GetEventType() == T::GetStaticType())	// 将T与m_Event的类型进行对比
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}