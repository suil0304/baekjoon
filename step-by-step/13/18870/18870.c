#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct OriginalIndexWithNum {
    int originalIndex;
    long num;
} OriginalIndexWithNum;

long compareNum(const void* a, const void* b);
int compareIndex(const void* a, const void* b);

int main() {
    int n;
    scanf("%d", &n);

    OriginalIndexWithNum* nums;
    nums = (OriginalIndexWithNum*) malloc(sizeof(OriginalIndexWithNum) * n);

    for(int i = 0; i < n; i++) {
        OriginalIndexWithNum num;
        scanf("%ld", &num.num);
        num.originalIndex = i;

        nums[i] = num;
    }

    qsort(nums, n, sizeof(OriginalIndexWithNum), compareNum);

    int prev = INT_MAX;
    int compress = 0;
    for(int i = 0; i < n; i++) {
        if(prev == INT_MAX) {
            prev = nums[i].num;
            nums[i].num = compress;

            continue;
        }

        if(nums[i].num > prev) {
            compress++;
            prev = nums[i].num;
            nums[i].num = compress;
        }
        else {
            nums[i].num = compress;
        }
    }

    qsort(nums, n, sizeof(OriginalIndexWithNum), compareIndex);

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i].num);
    }

    free(nums);

    return 0;
}

long compareNum(const void* a, const void* b) {
    return ((OriginalIndexWithNum*) a)->num - ((OriginalIndexWithNum*) b)->num;
}

int compareIndex(const void* a, const void* b) {
    return ((OriginalIndexWithNum*) a)->originalIndex - ((OriginalIndexWithNum*) b)->originalIndex;
}