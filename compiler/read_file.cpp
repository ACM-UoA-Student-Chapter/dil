/*
* Copyright: Copyright ssiatras (Stathis Siatras) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   ssiatras (Stathis Siatras)
*/
#include "read_file.h"
#include <fstream>
#include <sstream>
#include <string>

/*
 * This function reads the content of a text file as a whole into memory as a
 * NULL-terminated, contiguous array of characters.
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

  std::ifstream finput(filename, std::ios::in | std::ios::binary);
  if (!finput) {
  	return NULL;
  }

  std::ostringstream contents;
  contents << finput.rdbuf();
  finput.close();

  std::string str = contents.str();
  long int fsize = str.size();

  char *cstr = new char[fsize + 1];
  strcpy(cstr, str.c_str());

  return cstr;
}