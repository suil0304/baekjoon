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

    int isSwaped = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;

                isSwaped = 1;
            }
        }

        if(!isSwaped) {
            break;
        }
        isSwaped = 0;
    }

    for(int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }

    free(nums);

    return 0;
}