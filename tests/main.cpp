#include "./lp_hash_table_test.h"
#include <assert.h>
#include <iostream>

int main() {
    int res = test_hash_table();
    assert(res == 0);

    std::cout << "\x1b[0;32m" << "All tests passed! \x1b[0m" << std::endl;
    return 0;
}
