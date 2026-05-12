#pragma once

#ifdef _WIN32
#  include <windows.h>

namespace utf8_console_detail {
struct Utf8ConsoleInitializer {
    Utf8ConsoleInitializer() {
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    }
};

inline const Utf8ConsoleInitializer g_utf8_console_initializer{};
} // namespace utf8_console_detail
#endif
