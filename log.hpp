
#pragma once

#include <utility>
#include <cstdio>
#include <cstdlib>
#include "panic.hpp"

namespace log
{
    namespace detail
    {
        template <typename T>
        constexpr char modifier[5] = "%s%s";

        template <>
        constexpr char modifier<char>[5] = "%c%s";

        template <>
        constexpr char modifier<int>[5] = "%d%s";

        template <>
        constexpr char modifier<float>[5] = "%f%s";

        template <>
        constexpr char modifier<double>[6] = "%lf%s";

        template <>
        constexpr char modifier<bool>[5] = "%d%s";

        template <typename First, typename ...Rest>
        void print(First&& first, Rest&&... rest)
        {
            using decayed = typename std::decay<First>::type;

            if constexpr (sizeof...(rest) > 1UL)
            {
                if (std::printf(modifier<decayed>, std::forward<First>(first), " ") < 0)
                    panic("log::detail::print");

                print(std::forward<Rest>(rest)...);
            }
            else
            {
                if (std::printf(modifier<decayed>, std::forward<First>(first), "\n") < 0)
                    panic("log::detail::print");
            }
        }
    }

    template <typename ...Args>
    void syntax_error(Args&&... args)
    {
        detail::print("\033[31mSyntax Error:\033[0m", std::forward<Args>(args)...);
    }
}

