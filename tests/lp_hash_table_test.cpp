#include <assert.h>
#include "lp_hash_table.h"
#include "./lp_hash_table_test.h"

int test_hash_table() {
    lp_hash_table<int> table = lp_hash_table<int>();

    int res = table.insert("key", 1);
    assert(res == 0);

    int val = table.find("key");
    assert(val == 1);

    return 0;
}
