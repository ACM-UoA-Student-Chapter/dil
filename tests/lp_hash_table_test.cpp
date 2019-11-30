#include <iostream>
#include <assert.h>
#include "lp_hash_table.h"
#include "./lp_hash_table_test.h"


typedef struct test_type {
public:
    int val;

    test_type(int v) {
        this->val = v;
    }
} test_type;

bool test_hash_table() {
    lp_hash_table<test_type> table = lp_hash_table<test_type>(1);

    test_type t = test_type(1);
    int res = table.insert("key", t);
    assert(res == true);

    test_type *r;
    r = table.find("key");
    assert(r->val == 1);

    return true;
}

bool test_many_key_insertion() {


    lp_hash_table<test_type> table = lp_hash_table<test_type>(5);

    test_type t1 = test_type(1);
    test_type t2 = test_type(2);
    test_type t3 = test_type(3);
    test_type t4 = test_type(4);
    test_type t5 = test_type(5);

    int res1;
    res1 = table.insert("key1", t1);
    assert(res1 == true);

    int res2;
    res2 = table.insert("key2", t2);
    assert(res2 == true);

    int res3;
    res3 = table.insert("key3", t3);
    assert(res3 == true);

    int res4;
    res4 = table.insert("key4", t4);
    assert(res4 == true);

    int res5;
    res5 = table.insert("key5", t5);
    assert(res5 == true);

    test_type *r;

    r = table.find("key2");
    assert(r->val = 2);

    r = table.find("key3");
    assert(r->val = 3);

    r = table.find("key4");
    assert(r->val = 4);

    r = table.find("key5");
    assert(r->val = 5);

    return true;
}
