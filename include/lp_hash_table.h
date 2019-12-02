#ifndef DIL_LP_HASH_TABLE_H
#define DIL_LP_HASH_TABLE_H

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <type_traits>

template <typename T> struct lp_hash_table {
  static_assert(std::is_pointer<T>::value, "T must be a pointer");

private:
  const char **keys;
  T *values;
  size_t nbuckets;

  unsigned int hash(const char *key) {
    // TODO: implement a better hashing method
    return ((uintptr_t)key % this->nbuckets);
  }

  int find_index(const char *key) {

    int index = this->hash(key);
    int i = index;

    while (this->keys[i] != nullptr) {
      if (this->keys[i] == key) {
        return i;
      }

      i++;
      if (i == this->nbuckets)
        i = 0; // Wrap around at the start
      if (i == index)
        return -1; // We have traversed the whole table
    }

    return i; // We found an empty spot.
  }

public:
  /*
   * Constructor. Assumes that `elems > 0`
   */
  lp_hash_table(int elems) {
    assert(elems > 0);

    this->nbuckets = elems * 1.3;

    // TODO: use our own allocator when it is ready.
    keys = (const char **)calloc(this->nbuckets, sizeof(const char *));
    values = (T *)calloc(this->nbuckets, sizeof(T));
  };

  /*
   * @return. nothing. we are sure that we can insert
   */
  void insert(const char *key, T value) {

    int i = find_index(key);
    assert(i != -1);
    assert(this->keys[i] != key);
    this->keys[i] = key;
    this->values[i] = value;
  };

  /*
   * @return - Copy of the value under key or NULL if it does not exist
   */
  T find(const char *key) {

    int i = find_index(key);
    if (i == -1) {
      return NULL;
    }
    if (this->keys[i] != nullptr) {
      assert(this->values[i] != nullptr);
      return this->values[i];
    } else {
      return NULL;
    }
  };
};

#endif // DIL_LP_HASH_TABLE_H
