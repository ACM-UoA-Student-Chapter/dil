/*
* Copyright: Copyright ssiatras (Stathis Siatras) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   ssiatras (Stathis Siatras)
*/
#include "read_file.h"
#include <cstdio>
#include <cstdlib>

/*
 * This function reads the content of a text file as a whole into memory as a
 * NULL-terminated, contiguous array of characters.
 *
 * It only supports ASCII files with one-byte endlines;
 * (e.g. UNIX format endlines).
 *
 * Params:
 *    filepath = The path of the file to be read.
 * Returns:
 *    A pointer to an array of characters (the content of the file).
 */
const char *read_file_into_memory(const char *filepath) {
  if (filepath == NULL) {
    return NULL;
  }

  FILE *finput = fopen(filepath, "r");
  if (finput == NULL) {
    return NULL;
  }

  if (fseek(finput, 0, SEEK_END) != 0) {
    fclose(finput);
    return NULL;
  }

  long int fsize = ftell(finput);
  if (fsize == -1) {
    fclose(finput);
    return NULL;
  }

  if (fseek(finput, 0, SEEK_SET) != 0) {
    fclose(finput);
    return NULL;
  }

  char *string = new char[fsize + 1];
  if (string == NULL) {
    fclose(finput);
    return NULL;
  }
  if (fread(string, 1, fsize, finput) != fsize) {
    return NULL;
  }
  string[fsize] = '\0';

  if (fclose(finput) == EOF) {
    return NULL;
  }

  return string;
}