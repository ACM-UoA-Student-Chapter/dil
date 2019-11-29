#ifndef DIL_LP_HASH_TABLE_H
#define DIL_LP_HASH_TABLE_H

#include <stdlib.h>
#include <assert.h>

template <typename T>
struct lp_hash_table {
private:
    const char **pointers;
    T *data;
    int buckets;

    unsigned int hash(const char *key) {

    };

public:

    /*
     * Constructor. Assumes that `elems > 0`
     */
    lp_hash_table(int elems) {
        assert(elems > 0);

        buckets = elems;
        pointers = (const char **)malloc(buckets * sizeof(const char *));

        data = (T *)malloc(buckets * sizeof(T));
    };

    /*
     * @return - 0 means everything went ok, -1 means there was an error
     */
    int insert(const char *key, T value) {
        return 0;
    };

    /*
     * @return - Copy of the data under key. NULL if key does not exist
     */
    T find(const char *key) {
        T value;
        return value;
    };
};

#endif //DIL_LP_HASH_TABLE_H
