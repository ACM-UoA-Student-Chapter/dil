
#pragma once

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>

inline void panic(bool condition)
{
    if (condition)
    {
        char buff[256UL];

        std::printf("%s:%s:%d: %s", __FILE__, __func__, __LINE__, strerror_r(errno, buff, sizeof(buff)));

        std::exit(EXIT_FAILURE);
    }
}
