#include <iostream>
#include <assert.h>
#include "lp_hash_table.h"
#include "./lp_hash_table_test.h"


typedef struct test_type {
public:
    int val;
} test_type;

int test_hash_table() {
    std::cout << "Creating table of 1 element" << std::endl;
    lp_hash_table<test_type> table = lp_hash_table<test_type>(1);

    test_type t;
    t.val = 1;
    std::cout << "Inserting 1 element with value 1 into hash table" << std::endl;
    int res = table.insert("key", t);
    assert(res == 0);

    test_type r;
    std::cout << "Trying to find that element" << std::endl;
    int ret = table.find("key", &r);
    assert(ret == 0);
    assert(r.val == 1);

    return 0;
}
