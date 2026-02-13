#pragma once
#include <fmt/color.h>

enum LEVEL
{
	LOG,
	INFO,
	WARNING,
	ERR,
	SUCCESS,
	DEBUG
};

class System
{
public:
	template<typename... Args>
	static void PrintLn(LEVEL level, fmt::format_string<Args...> fmt_str, Args&&... args)
	{
		fmt::color color = fmt::color::white;
		switch (level) {
		case LOG:     color = fmt::color::wheat; break;
		case INFO:    color = fmt::color::aqua; break;
		case WARNING: color = fmt::color::yellow; break;
		case ERR:     color = fmt::color::red; break;
		case SUCCESS:     color = fmt::color::green; break;
		case DEBUG:     color = fmt::color::pink; break;
		default:     color = fmt::color::white; break;
		}

		fmt::print(fg(color), "{}\n", fmt::format(fmt_str, std::forward<Args>(args)...));
	}
};
