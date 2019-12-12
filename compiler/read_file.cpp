/*
* Copyright: Copyright ssiatras (Stathis Siatras) 2019.
* License:   $(LINK2 http://www.boost.org/LICENSE_1_0.txt, Boost License 1.0)
* Authors:   ssiatras (Stathis Siatras)
*/
#include "read_file.h"
#include <fstream>
#include <sstream>

/*
 * This function reads the content of a text file as a whole into memory as a
 * NULL-terminated, contiguous array of characters.
 *
 * Params:
 *    filepath = The path of the file to be read.
 * Returns:
 *    A C++ string object (the content of the file).
 */
std::string read_file_into_memory(const char *filepath) {
  if (filepath == NULL) {
    return std::string();
  }

  std::ifstream finput(filepath, std::ios::in | std::ios::binary);
  if (!finput) {
  	return std::string();
  }

  std::ostringstream contents;
  contents << finput.rdbuf();
  finput.close();

  return contents.str();
}