#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define HASH_POWER_NUM 31
#define HASH_MOD_NUM1 1000000007
#define HASH_MOD_NUM2 INT_MAX
#define INSERT_MOD_NUM 150001

typedef struct HashTable HashTable;

typedef struct HashItem {
    char* str;
    long long hash;
    int value;
} HashItem;

struct HashTable {
    HashItem* _items;
    int length;
    int (*get)(HashTable*, const char*, int);
    void (*set)(HashTable*, char*, int);
};

// hash
void initHashTable(HashTable* hashTable);
void destroyHashTable(HashTable* hashTable);
long long getHash(const char* str);
int _getHashTable(HashTable* hashTable, const char* str, int defaultNum);
void _setHashTable(HashTable* hashTable, char* str, int n);
// compare
int compare(const void* a, const void* b);

int main() {
    HashTable hashTable;
    initHashTable(&hashTable);

    int t, maxLength;
    scanf("%d %d", &t, &maxLength);

    for(int i = 0; i < t; i++) {
        char english[11];
        scanf("%s", english);

        if(strlen(english) >= maxLength) {
            hashTable.set(&hashTable, english, hashTable.get(&hashTable, english, 0) + 1);
        }
    }

    HashItem* hashItemArray = (HashItem*) malloc(sizeof(HashItem) * hashTable.length);
    int hashItemIndex = 0;
    for(int i = 0; i < INSERT_MOD_NUM; i++) {
        if(hashTable._items[i].hash != 0) {
            hashItemArray[hashItemIndex] = hashTable._items[i];
            hashItemIndex++;
        }
    }
    
    qsort(hashItemArray, hashTable.length, sizeof(HashItem), compare);

    for(int i = 0; i < hashTable.length; i++) {
        printf("%s\n", hashItemArray[i].str);
    }

    destroyHashTable(&hashTable);
    free(hashItemArray);

    return 0;
}

void initHashTable(HashTable* hashTable) {
    hashTable->_items = (HashItem*) calloc(INSERT_MOD_NUM, sizeof(HashItem));
    hashTable->length = 0;

    hashTable->get = _getHashTable;
    hashTable->set = _setHashTable;
}

void destroyHashTable(HashTable* hashTable) {
    for(int i = 0; i < INSERT_MOD_NUM; i++) {
        if(hashTable->_items[i].hash != 0) {
            free(hashTable->_items[i].str);
        }
    }

    free(hashTable->_items);
    hashTable->length = 0;

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
    while(hashTable->_items[index].hash != 0) {
        if(hashTable->_items[index].hash == hash) {
            return hashTable->_items[index].value;
        }

        index = (index + 1) % INSERT_MOD_NUM;

        if(index == originalIndex) {
            break;
        }
    }

    return defaultNum;
}

void _setHashTable(HashTable* hashTable, char* str, int n) {
    long long hash = getHash(str);
    int index = hash % INSERT_MOD_NUM;
    while(hashTable->_items[index].hash != 0) {
        if(hashTable->_items[index].hash == hash) {
            hashTable->_items[index].value = n;
            return; 
        }
        index = (index + 1) % INSERT_MOD_NUM;
    }

    hashTable->_items[index].str = strdup(str);
    hashTable->_items[index].hash = hash;
    hashTable->_items[index].value = n;
    hashTable->length++;
}

int compare(const void* a, const void* b) {
    if(((HashItem*) b)->value != ((HashItem*) a)->value) {
        return ((HashItem*) b)->value - ((HashItem*) a)->value;
    }

    int length1 = strlen(((HashItem*) a)->str);
    int length2 = strlen(((HashItem*) b)->str);
    if(length1 != length2) {
        return length2 - length1;
    }
    return strcmp(((HashItem*) a)->str, ((HashItem*) b)->str);
}