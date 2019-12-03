
#include "log.hpp"

int main()
{
    const char * name = "Vasilis", * surname = "Sioros";

    syntax_error("This is not a syntax error but I", name, surname, "am", 22, "years old");

    return 0;
}
