#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* nums;
    nums = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    for(int i = 0; i < m; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        int* reverseNum;
        reverseNum = (int*) calloc(end - (start - 1), sizeof(int));
        for(int j = 0; j <= (end - 1) - (start - 1); j++) {
            reverseNum[j] = nums[(end - 1) - j];
        }
        for(int j = 0; j <= (end - 1) - (start - 1); j++) {
            nums[(start - 1) + j] = reverseNum[j];
        }
        free(reverseNum);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    free(nums);

    return 0;
}