#include "./lp_hash_table_test.h"
#include "lp_hash_table.h"
#include <assert.h>
#include <iostream>
#include <cstring>

class test_type {
public:
  int val;

  test_type(int v) { this->val = v; }
};

bool test_hash_table() {
  LpHashTable<test_type *> table = LpHashTable<test_type *>(1);

  const char *k = "key";
  test_type *t = new test_type(1);
  table.insert(k, t);

  test_type *r;
  r = table.find(k);
  assert(r->val == 1);

  return true;
}

bool test_many_key_insertion() {

  LpHashTable<test_type *> table = LpHashTable<test_type *>(5);

  test_type *t1 = new test_type(1);
  test_type *t2 = new test_type(2);
  test_type *t3 = new test_type(3);
  test_type *t4 = new test_type(4);
  test_type *t5 = new test_type(5);

  const char *k1 = "key1";
  const char *k2 = "key2";
  const char *k3 = "key3";
  const char *k4 = "key4";
  const char *k5 = "key5";
  table.insert(k1, t1);
  table.insert(k2, t2);
  table.insert(k3, t3);
  table.insert(k4, t4);
  table.insert(k5, t5);

  test_type *r;

  r = table.find(k1);
  assert(r->val = 1);

  r = table.find(k2);
  assert(r->val = 2);

  r = table.find(k3);
  assert(r->val = 3);

  r = table.find(k4);
  assert(r->val = 4);

  r = table.find(k5);
  assert(r->val = 5);

  return true;
}

/*
 * NOTE: this test will fail if the compiler implementation interns strings.
 * IE if two `const char *` have the same address in memory this test will fail.
 */
bool test_memory_location_functionality() {
  LpHashTable<test_type *> table = LpHashTable<test_type *>(3);

  test_type *t1 = new test_type(1);

  const char *k1 = "key1";
  const char *k2 = "key1";
  assert(strcmp(k1, k2) == 0);

  const char *not_exist = "not_exist";

  table.insert(k1, t1);

  test_type *r;

  // test that we get NULL for keys that don't exist
  r = table.find(not_exist);
  assert(r == NULL);

  // test that identical keys in different memory locations
  // return NULL. This piece of code assumes that the compiler
  // won't optimize strings in such a way that 2 identical strings
  // point to the same memory location
  r = table.find(k2);
  assert(r == NULL);

  return true;
}
