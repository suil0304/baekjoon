#include <stdio.h>
#include <stdlib.h>

int compareNum(const void* a, const void* b);

int main() {
    int nums[5];
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int num;
        scanf("%d", &num);

        sum += num;
        nums[i] = num;
    }

    qsort(nums, 5, sizeof(int), compareNum);

    printf("%d\n", sum / 5);
    printf("%d\n", nums[2]);

    return 0;
}

int compareNum(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}