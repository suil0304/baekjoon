#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareNum(const void* a, const void* b);

int main() {
    char str[11];
    scanf("%s", str);

    int length = strlen(str);

    int* nums;
    nums = (int*) malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++) {
        nums[i] = str[i] - '0';
    }

    qsort(nums, length, sizeof(int), compareNum);

    for(int i = 0; i < length; i++) {
        printf("%d", nums[i]);
    }

    free(nums);

    return 0;
}

int compareNum(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}