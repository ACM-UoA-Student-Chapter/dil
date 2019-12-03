
#pragma once

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>

inline void panic(const char * message)
{
    char buff[256UL];

    std::printf("%s:%s:%d: %s [%s]", __FILE__, __func__, __LINE__, message, strerror_r(errno, buff, sizeof(buff)));

    std::exit(EXIT_FAILURE);
}
