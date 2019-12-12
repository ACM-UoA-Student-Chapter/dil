/*
* Copyright: Copyright ssiatras (Stathis Siatras) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   ssiatras (Stathis Siatras)
*/
#include "read_file.h"
#include <cstring>
#include <cassert>
#include <fstream>

int main(void) {
  assert(read_file_into_memory(NULL).length() == 0);

  const char *test_filepath = "./test_file.txt";
  std::ofstream ftest(test_filepath);
  if (!ftest) {
    return -1;
  }

  const char *test_string = "Testing\n\nread_file_into_memory\n\nfunction";
  ftest << test_string;
  ftest.close();

  std::string output_str = read_file_into_memory(test_filepath);
  const char *output_c_str = output_str.c_str();
  assert(strcmp(output_c_str, test_string) == 0);

  if (remove(test_filepath) != 0) {
    return -2;
  }

  return 0;
}