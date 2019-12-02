#include "./lp_hash_table_test.h"
#include "lp_hash_table.h"
#include <assert.h>
#include <iostream>

class test_type {
public:
  int val;

  test_type(int v) { this->val = v; }
};

bool test_hash_table() {
  lp_hash_table<test_type *> table = lp_hash_table<test_type *>(1);

  test_type *t = new test_type(1);
  table.insert("key", t);

  test_type *r;
  r = table.find("key");
  assert(r->val == 1);

  return true;
}

bool test_many_key_insertion() {

  lp_hash_table<test_type *> table = lp_hash_table<test_type *>(5);

  test_type *t1 = new test_type(1);
  test_type *t2 = new test_type(2);
  test_type *t3 = new test_type(3);
  test_type *t4 = new test_type(4);
  test_type *t5 = new test_type(5);

  table.insert("key1", t1);
  table.insert("key2", t2);
  table.insert("key3", t3);
  table.insert("key4", t4);
  table.insert("key5", t5);

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
