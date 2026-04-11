#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_POWER 31
#define HASH_MOD_NUM1 1000000007
#define HASH_MOD_NUM2 2147483647
#define HASH_INSERT_MOD_NUM 750007

long long hashArray[HASH_INSERT_MOD_NUM] = {0, };

void hashInsert(long long hash1, long long hash2);

int main() {
    char str[1001];
    scanf("%s", str);

    int length = strlen(str);
    for(int i = 0; i < length; i++) {
        long long hashNum1 = 0, hashNum2 = 0;
        long long hashPower1 = 1, hashPower2 = 1;
        for(int j = 0; i + j < length; j++) {
            hashNum1 = (hashNum1 + (str[i + j] - 'a' + 1) * hashPower1) % HASH_MOD_NUM1;
            hashPower1 = (hashPower1 * HASH_POWER) % HASH_MOD_NUM1;

            hashNum2 = (hashNum2 + (str[i + j] - 'a' + 1) * hashPower2) % HASH_MOD_NUM2;
            hashPower2 = (hashPower2 * HASH_POWER) % HASH_MOD_NUM2;

            hashInsert(hashNum1, hashNum2);
        }
    }

    int count = 0;
    for(int i = 0; i < HASH_INSERT_MOD_NUM; i++) {
        if(hashArray[i] != 0) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}

void hashInsert(long long hash1, long long hash2) {
    long long hashCombined = (hash1 << 32) | hash2;
    int index = hashCombined % HASH_INSERT_MOD_NUM;
    while(hashArray[index] != 0) {
        if(hashArray[index] == hashCombined) {
            return;
        }
        index = (index + 1) % HASH_INSERT_MOD_NUM;
    }

    hashArray[index] = hashCombined;
}