#include <vector>
#include <string>

char* add_string(char *string, std::vector<char*> &old_strings) {
    //check if the string is stored
    for (size_t i = 0; i < old_strings.size(); i++) {
        if (!strcmp(string, old_strings[i])) {
            return old_strings[i];
        }
    }

    //if it isn't stored create a new
    char *new_string = new char[strlen(string) + 1];
    strncpy(new_string, string, strlen(string) + 1);
    old_strings.push_back(new_string);
    
    return new_string;
}