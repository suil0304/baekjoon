#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

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

    qsort(nums, n, sizeof(int), compare);

    int queryNum;
    scanf("%d", &queryNum);
    for(int i = 0; i < queryNum; i++) {
        int query;
        scanf("%d", &query);

        printf("%d ", bsearch(&query, nums, n, sizeof(int), compare) != NULL);
    }

    free(nums);
    
    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}