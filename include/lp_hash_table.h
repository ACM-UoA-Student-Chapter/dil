#ifndef DIL_LP_HASH_TABLE_H
#define DIL_LP_HASH_TABLE_H

template <typename T>
struct lp_hash_table {
private:
    const char **pointers;
    T *data;

public:

    lp_hash_table() {};

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
