/*
* Copyright: Copyright ssiatras (Stathis Siatras) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   ssiatras (Stathis Siatras)
*/
#include "read_file.h"
#include <cstdio>
#include <cstring>
#include <cassert>

int main(void) {
  assert(read_file_into_memory(NULL) == NULL);

  const char *test_filepath = "./test_file.txt";
  FILE *ftest = fopen(test_filepath, "w");
  if (ftest == NULL) {
    return -1;
  }

  const char *test_string = "Testing\n\nread_file_into_memory\n\nfunction";
  fwrite(test_string, strlen(test_string), 1, ftest);
  if (fclose(ftest) == EOF) {
    return -1;
  }

  const char *output_string = read_file_into_memory(test_filepath);
  assert(strcmp(output_string, test_string) == 0);

  delete[] output_string;
  if (remove(test_filepath) != 0) {
    return -2;
  }

  return 0;
}