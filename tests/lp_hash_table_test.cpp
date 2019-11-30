#include <iostream>
#include <assert.h>
#include "lp_hash_table.h"
#include "./lp_hash_table_test.h"


typedef struct test_type {
public:
    int val;
} test_type;

int test_hash_table() {
    std::cout << "Hash Table" << std::endl;
    lp_hash_table<test_type> table = lp_hash_table<test_type>(1);

    test_type t;
    t.val = 1;
    int res = table.insert("key", t);
    assert(res == true);

    test_type *r;
    r = table.find("key");
    assert(r->val == 1);

    std::cout << "\x1b[0;32m Hash table tests passed! \x1b[0m" << std::endl;
    return 0;
}
