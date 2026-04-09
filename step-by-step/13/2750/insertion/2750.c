#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* nums;
    nums = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        nums[i] = num;
    }

    for(int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;

        for(j; j >= 0 && nums[j] > key; j--) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = key;
    }

    for(int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }

    free(nums);

    return 0;
}