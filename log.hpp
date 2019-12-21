/*
 * Copyright: Copyright billsioros (Sioros Vasileios) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   billsioros (Sioros Vasileios)
 */

#pragma once

#include <cstdio>

inline void log(const char *arg) { std::printf("%s ", arg); }

inline void log(char arg) { std::printf("%c ", arg); }

inline void log(int arg) { std::printf("%d ", arg); }

inline void log(float arg) { std::printf("%f ", arg); }

inline void log(double arg) { std::printf("%lf ", arg); }

inline void log(bool arg) { std::printf("%s ", arg ? "true" : "false"); }

template <typename First, typename... Rest>
inline void log(First first, Rest... rest) {
  log(first);
  log(rest...);
}

template <typename... Args> inline void syntax_error(Args... args) {
  // "\033[31m": This ANSI escape code sets the terminal' s text color to red
  // "\033[0m":  This ANSI escape code resets the terminal' s text color
  // "\033[31mSyntax Error:\033[0m": Using the two together results in the
  //                                 string "Syntax Error:" being colored red

  log("\033[31mSyntax Error:\033[0m", args...);
}
