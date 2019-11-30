#include "./lp_hash_table_test.h"
#include <assert.h>
#include <iostream>

int main() {
    std::cout << "Hash Table" << std::endl;
    bool res = test_hash_table();
    assert(res == true);

    res = test_many_key_insertion();
    assert(res == true);

    std::cout << "\x1b[0;32m Hash table tests passed! \x1b[0m" << std::endl;

    std::cout << "\x1b[0;32m" << "All tests passed! \x1b[0m" << std::endl;
    return 0;
}
