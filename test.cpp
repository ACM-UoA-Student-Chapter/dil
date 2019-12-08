#include "int_scan.hpp"
#include <cassert>
#include <cstdint>
#include <cstdio>

/*
assert that that read_int returns the EMPTY_NUM_EXPR_ERROR code for the given
input string.
*/
static void assert_empty(const char *input) {
  int value;
  int error_code = read_int(input, &value);
  assert(error_code == EMPTY_NUM_EXPR_ERROR);
  printf("SUCCESS: read_int(\"%s\",&value) returns empty numerical expression "
         "error code.\n",
         input);
}

/*
assert that that read_int returns the OUT_OF_BOUNDS_ERROR code for the given
input string.
*/
static void assert_out_of_bounds(const char *input) {
  int value;
  int error_code = read_int(input, &value);
  assert(error_code == OUT_OF_BOUNDS_ERROR);
  printf("SUCCESS: read_int(\"%s\",&value) returns out of bounds error code.\n",
         input);
}

/*
assert that that read_int returns the OVERFLOW_ERROR code for the given input
string.
*/
static void assert_overflow(const char *input) {
  int value;
  int error_code = read_int(input, &value);
  assert(error_code == OVERFLOW_ERROR);
  printf("SUCCESS: read_int(\"%s\",&value) returns overflow error code.\n",
         input);
}

/*
assert that read_int returns the INT_SCANNED code for the given input string and
the value is set to expected_val
*/
static void assert_success(const char *input, int expected_val) {
  int value;
  int error_code = read_int(input, &value);
  assert(error_code == INT_SCANNED);
  assert(value == expected_val);
  printf(
      "SUCCESS: read_int(\"%s\",&value) returns success code with value=%d.\n",
      input, expected_val);
}

int main(void) {
  init_char_to_digit();

  assert_empty("");
  assert_empty("0x");
  assert_empty("0X");

  assert_out_of_bounds("+1312");
  assert_out_of_bounds("018329");
  assert_out_of_bounds("0fff");
  assert_out_of_bounds("0xfs8f");

  assert_overflow("2147483648");
  assert_overflow("020000000000");
  assert_overflow("0X80000000");

  assert_success("10", 10);
  assert_success("017", 017);
  assert_success("0xaF", 0xaf);
  assert_success("0", 0);
  assert_success("0X0", 0);
  assert_success("0000", 0);
  assert_success("2147483647", 2147483647);
  assert_success("017777777777", 2147483647);
  assert_success("0X7fffffff", 2147483647);

  return 0;
}
