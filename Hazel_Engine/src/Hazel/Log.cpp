#include "hzpch.h"
#include "Log.h"


namespace Hazel {

    HAZEL_API std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    HAZEL_API std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");     //设置 Log 输出的格式
        s_CoreLogger = spdlog::stdout_color_mt("HAZEL");    //为 Log 对象命名
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }

}