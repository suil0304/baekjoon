#include <stdio.h>
#include <stdlib.h>

#define HASH_POWER 31
#define HASH_INSERT_MOD_NUM 100003

#define min(a, b) (\
    (a < b) ? (a) : (b) \
)

typedef struct HashTable HashTable;

struct HashTable {
    long long* _keys;
    int* _values;
    int length;
    int (*get)(HashTable*, long long);
    void (*set)(HashTable*, long long, int);
};

// recursive function
int recursive(HashTable* hashTable, long long n);
// hash function
int _getValue(HashTable* hashTable, long long hash);
void _setValue(HashTable* hashTable, long long hash, int value);
void initHashTable(HashTable* hashTable);
void destroyHashTable(HashTable* hashTable);

int main() {
    HashTable hashTable;
    initHashTable(&hashTable);

    long long n;
    scanf("%lld", &n);

    printf("%d", recursive(&hashTable, n));

    destroyHashTable(&hashTable);

    return 0;
}

int recursive(HashTable* hashTable, long long n) {
    if(n == 1) {
        return 0;
    }
    else if(n == 2 || n == 3) {
        return 1;
    }

    int value = hashTable->get(hashTable, n);
    if(value != -1) {
        return value;
    }

    int three = recursive(hashTable, (n - (n % 3)) / 3) + (n % 3) + 1;
    int two = recursive(hashTable, (n - (n % 2)) / 2) + (n % 2) + 1;
    hashTable->set(hashTable, n, min(three, two));

    return min(three, two);
}

int _getValue(HashTable* hashTable, long long hash) {
    int index = hash % HASH_INSERT_MOD_NUM;
    int originalIndex = index;

    while(hashTable->_keys[index] != 0) {
        if(hashTable->_keys[index] == hash) {
            return hashTable->_values[index];
        }

        index = (index + 1) % HASH_INSERT_MOD_NUM;

        if(originalIndex == index) {
            break;
        }
    }

    return -1;
}

void _setValue(HashTable* hashTable, long long hash, int value) {
    int index = hash % HASH_INSERT_MOD_NUM;

    while(hashTable->_keys[index] != 0) {
        if(hashTable->_keys[index] == hash) {
            hashTable->_values[index] = value;
            return;
        }
        index = (index + 1) % HASH_INSERT_MOD_NUM;
    }

    hashTable->_keys[index] = hash;
    hashTable->_values[index] = value;
    hashTable->length++;
}

void initHashTable(HashTable* hashTable) {
    hashTable->length = 0;

    hashTable->_keys = (long long*) calloc(HASH_INSERT_MOD_NUM, sizeof(long long));
    hashTable->_values = (int*) calloc(HASH_INSERT_MOD_NUM, sizeof(int));

    hashTable->get = _getValue;
    hashTable->set = _setValue;
}

void destroyHashTable(HashTable* hashTable) {
    hashTable->length = -1;

    free(hashTable->_keys);
    free(hashTable->_values);

    hashTable->get = NULL;
    hashTable->set = NULL;
}