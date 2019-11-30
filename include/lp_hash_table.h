#ifndef DIL_LP_HASH_TABLE_H
#define DIL_LP_HASH_TABLE_H

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

template <typename T>
struct lp_hash_table {
private:
    const char **keys;
    T *values;
    int nbuckets;

    unsigned int hash(const char *key) {
        // TODO: implement a better hashing method
        return ((uintptr_t)key % this->nbuckets);
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
        values = (T *)malloc(this->nbuckets * sizeof(T));

    };

    /*
     * @return. true - everything went ok. false - something went wrong
     */
    bool insert(const char *key, T value) {

        int index = this->hash(key);
        int i = index;

        while(this->keys[i] != nullptr) {
            if (this->keys[i] == key) {
                return false;
            }

            i++;
            if (i == this->nbuckets)
                i = 0; // Wrap around at the start
            if (i == index)
                return false; // We have traversed the whole table and found no spot to insert in
        }

        this->keys[i] = key;
        this->values[i] = value;
        return true;
    };

    /*
     * @return - Copy of the value under key or NULL if it does not exist
     */
    T* find(const char *key) {
        int index = this->hash(key);

        int i = index;

        while(this->keys[i] != nullptr) {
            if (this->keys[i] == key) {
                assert(this->keys[i] != nullptr);
                return &this->values[i];
            } else if (this->keys[i] == nullptr) {
                return NULL;
            }

            i++;
            if (i == this->nbuckets)
                i = 0; // Wrap around at the start
            if (i == index)
                return NULL; // We have traversed the whole table and didn't find the element
        }
        return NULL;
    };

    /*
     * We apparently don't need this
     * int remove(const char *key);
     */
};

#endif //DIL_LP_HASH_TABLE_H
