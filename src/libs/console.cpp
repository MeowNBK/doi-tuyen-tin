#include "libs/console.h"

#ifdef _WIN32
    #include <windows.h>
#endif

namespace meow {
    void set_codepoint(unsigned int codepoint) noexcept {
        #ifdef _WIN32
            SetConsoleOutputCP(codepoint);
            SetConsoleOutputCP(codepoint);
        #endif
    }
}