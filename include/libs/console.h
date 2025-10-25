#ifndef CONSOLE_H
#define CONSOLE_H

namespace meow {
    void set_codepoint(unsigned int) noexcept;
    inline void set_utf8() noexcept { set_codepoint(65001); }
}

#endif