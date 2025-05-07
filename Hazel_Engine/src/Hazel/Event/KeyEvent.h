#pragma once

#include "Event.h"

namespace Hazel {
	
	class HAZEL_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)	// 通过按位或，可以将多个标志组合成一个值
							// 将 EventCategoryKeyboard 和 EventCategoryInput 组合成一个值，表示该事件同时属于键盘事件和输入事件
	protected:
		KeyEvent(int keycode)
			:m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount)
			:KeyEvent(keycode), m_RepeatCount(repeatcount) {
		}

		inline int GetRepeatCount() { return m_RepeatCount; }

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent " << m_KeyCode << " (" << m_RepeatCount << " repeats.)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode) {
		}

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}