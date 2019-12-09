# Coding Guide

## Most important guideline
1) Write the simplest code possible. Let me re-iterate that: **_Write the simplest code possible_**
That includes avoiding all the C++ weirdness.
2) Use **clang-format**!

## General naming convention
We'll use `snake_case`, with a couple of exceptions:

### Enums
All caps should be used only for `enum`s, e.g.

```cpp
enum class TOK {
  UNDEFINED,
  INT_LIT,
  ...
};
```

### Globals
Global variables should start with 2 underscores (to make clear that they're global).

### structs / classes
`PascalCase` (to make clear that we have a custom type).

## General indentation style
We'll use the K&R style with the exception of functions. There are basically 2 types of people:
One type:
```cpp
if (...) {
}
```
Second type:
```cpp
if (...)
{
}
```
We'll basically be the first type in this project. :) This is generally called the [K&R style]([https://en.wikipedia.org/wiki/Indentation_style#K.26R](https://en.wikipedia.org/wiki/Indentation_style#K.26R)) from Kernighan and Ritchie. But K&R uses the second type in functions, e.g.:
```cpp
void foo()
{
}
```
We'll put the bracket in the same line in function definitions as well:
```cpp
void foo() {
}
```

## Misc

1) Templates should be used with care. Unfortunately, C++ has a very bad implementation of templates (because of the preprocessor) which results in huge compile times. So, we should have a very good reason to use them.
... To be continued
