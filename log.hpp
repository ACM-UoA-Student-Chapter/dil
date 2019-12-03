
#pragma once

#include <utility>
#include <cstdio>
#include <cstdlib>

inline void single_print(const char * arg)
{
    std::printf("%s ", arg);
}

inline void single_print(char arg)
{
    std::printf("%c ", arg);
}

inline void single_print(int arg)
{
    std::printf("%d ", arg);
}

inline void single_print(float arg)
{
    std::printf("%f ", arg);
}

inline void single_print(double arg)
{
    std::printf("%lf ", arg);
}

inline void single_print(bool arg)
{
    std::printf("%s ", arg ? "true" : "false");
}

template <typename Last>
inline void print(Last last)
{
    single_print(last); std::printf("\n");
}

template <typename First, typename Second, typename ...Rest>
inline void print(First first, Second second, Rest... rest)
{
    single_print(first); print(second, rest...);
}

template <typename ...Args>
inline void syntax_error(Args&&... args)
{
    print("\033[31mSyntax Error:\033[0m", std::forward<Args>(args)...);
}
