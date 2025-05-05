#pragma once

#include "Event.h"
#include "spdlog/fmt/ostr.h"

#include <sstream>

namespace Hazel {

	class HAZEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int height, unsigned int width)
			:m_Height(height), m_Width(width) {
		}

		inline unsigned int GetHeight() const { return m_Height; }
		inline unsigned int GetWidth() const { return m_Width; }

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Height << ", " << m_Width;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Height;
		unsigned int m_Width;
	};

	class HAZEL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
// ���spdlog��� fmt �����޷��������� ToString ����������������ػ����¼��� fmt �¼������������ToString����
#if 0
template <>
struct fmt::formatter<Hazel::WindowResizeEvent> {
	constexpr auto parse(fmt::format_parse_context& ctx) -> decltype(ctx.begin()) {
		return ctx.begin();
	}

	template <typename FormatContext>
	auto format(const Hazel::WindowResizeEvent& event, FormatContext& ctx) const -> decltype(ctx.out()) {
		return fmt::format_to(ctx.out(), "WindowResizeEvent: {}x{}", event.GetHeight(), event.GetWidth());
	}
};
#endif