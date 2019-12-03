
#pragma once

#include <utility>
#include <cstdio>
#include <cstdlib>
#include "panic.hpp"

inline void single_print(const char * arg, const char * next)
{
    panic(std::printf("%s%s", arg, next) < 0);
}

inline void single_print(char arg, const char * next)
{
    panic(std::printf("%c%s", arg, next) < 0);
}

inline void single_print(int arg, const char * next)
{
    panic(std::printf("%d%s", arg, next) < 0);
}

inline void single_print(float arg, const char * next)
{
    panic(std::printf("%f%s", arg, next) < 0);
}

inline void single_print(double arg, const char * next)
{
    panic(std::printf("%lf%s", arg, next) < 0);
}

inline void single_print(bool arg, const char * next)
{
    panic(std::printf("%s%s", arg ? "true" : "false", next) < 0);
}

template <typename First, typename ...Rest>
inline void print(First&& first, Rest&&... rest)
{
    if constexpr (sizeof...(rest) > 1UL)
    {
        single_print(std::forward<First>(first), " ");

        print(std::forward<Rest>(rest)...);
    }
    else
    {
        single_print(std::forward<First>(first), "\n");
    }
}

template <typename ...Args>
inline void syntax_error(Args&&... args)
{
    print("\033[31mSyntax Error:\033[0m", std::forward<Args>(args)...);
}
