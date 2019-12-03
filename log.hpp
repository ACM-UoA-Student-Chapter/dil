/*
 * Copyright: Copyright billsioros (Sioros Vasileios) 2019.
 * License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
 * Authors:   billsioros (Sioros Vasileios)
 */

#pragma once

#include <cstdio>

template <typename Arg> inline void log(Arg arg) { std::printf("%s ", arg); }

template <> inline void log<char>(char arg) { std::printf("%c ", arg); }

template <> inline void log<int>(int arg) { std::printf("%d ", arg); }

template <> inline void log<float>(float arg) { std::printf("%f ", arg); }

template <> inline void log<double>(double arg) { std::printf("%lf ", arg); }

template <> inline void log<bool>(bool arg) {
  std::printf("%s ", arg ? "true" : "false");
}

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
