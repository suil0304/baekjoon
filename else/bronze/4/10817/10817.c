#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
    int nums[3];
    for(int i = 0; i < 3; i++) {
        int num;
        scanf("%d", &num);

        nums[i] = num;
    }

    qsort(nums, 3, sizeof(int), compare);

    printf("%d", nums[1]);

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}