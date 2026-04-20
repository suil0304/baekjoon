#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define HASH_POWER_NUM 31
#define HASH_MOD_NUM1 1000000007
#define HASH_MOD_NUM2 INT_MAX
#define INSERT_MOD_NUM 150001

typedef struct HashTable HashTable;

struct HashTable {
    long long* _keys;
    int* _values;
    int (*get)(HashTable*, const char*, int);
    void (*set)(HashTable*, const char*, int);
};

void initHashTable(HashTable* hashTable);
void resetHashTable(HashTable* hashTable);
void destroyHashTable(HashTable* hashTable);
long long getHash(const char* str);
int _getHashTable(HashTable* hashTable, const char* str, int defaultNum);
void _setHashTable(HashTable* hashTable, const char* str, int n);

int main() {
    HashTable hashTable;
    initHashTable(&hashTable);

    int t;
    scanf("%d", &t);
    
    int count = 0;
    for(int i = 0; i < t; i++) {
        char str[21];
        scanf("%s", str);

        if(strcmp(str, "ENTER") == 0) {
            resetHashTable(&hashTable);
            continue;
        }

        if(!hashTable.get(&hashTable, str, 0)) {
            hashTable.set(&hashTable, str, 1);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}

void initHashTable(HashTable* hashTable) {
    hashTable->_keys = (long long*) calloc(INSERT_MOD_NUM, sizeof(long long));
    hashTable->_values = (int*) calloc(INSERT_MOD_NUM, sizeof(int));

    hashTable->get = _getHashTable;
    hashTable->set = _setHashTable;
}

void resetHashTable(HashTable* hashTable) {
    destroyHashTable(hashTable);
    initHashTable(hashTable);
}

void destroyHashTable(HashTable* hashTable) {
    free(hashTable->_keys);
    free(hashTable->_values);

    hashTable->get = NULL;
    hashTable->set = NULL;
}

long long getHash(const char* str) {
    long long base1 = 0;
    long long base2 = 0;
    long long power1 = 1;
    long long power2 = 1;
    
    int length;
    length = strlen(str);
    for(int i = 0; i < length; i++) {
        base1 = (base1 + str[i] * power1) % HASH_MOD_NUM1;
        base2 = (base2 + str[i] * power2) % HASH_MOD_NUM2;
        power1 = (power1 * HASH_POWER_NUM) % HASH_MOD_NUM1;
        power2 = (power2 * HASH_POWER_NUM) % HASH_MOD_NUM2;
    }

    return (base1 << 32) | base2;
}

int _getHashTable(HashTable* hashTable, const char* str, int defaultNum) {
    long long hash = getHash(str);
    int index = hash % INSERT_MOD_NUM;
    int originalIndex = index;
    while(hashTable->_keys[index] != 0) {
        if(hashTable->_keys[index] == hash) {
            return hashTable->_values[index];
        }

        index = (index + 1) % INSERT_MOD_NUM;

        if(index == originalIndex) {
            break;
        }
    }

    return defaultNum;
}

void _setHashTable(HashTable* hashTable, const char* str, int n) {
    long long hash = getHash(str);
    int index = hash % INSERT_MOD_NUM;
    while(hashTable->_keys[index] != 0) {
        if(hashTable->_keys[index] == hash) {
            hashTable->_values[index] = n;
            return; 
        }
        index = (index + 1) % INSERT_MOD_NUM;
    }

    hashTable->_keys[index] = hash;
    hashTable->_values[index] = n;
}