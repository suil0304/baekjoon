#include <stdio.h>
#include <stdlib.h>

int compareNum(const void* a, const void* b);
int lowerBound(int* arr, int low, int high, int key);
int upperBound(int* arr, int low, int high, int key);

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

    qsort(nums, n, sizeof(int), compareNum);

    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++) {
        int query;
        scanf("%d", &query);

        printf("%d ", upperBound(nums, 0, n, query) - lowerBound(nums, 0, n, query));
    }

    free(nums);

    return 0;
}

int compareNum(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int lowerBound(int* arr, int low, int high, int key) {
    if(low >= high) {
        return low;
    }

    int mid = low + (high - low) / 2;

    if(arr[mid] >= key) {
        high = mid;
    }
    else {
        low = mid + 1;
    }
    
    return lowerBound(arr, low, high, key);
}

int upperBound(int* arr, int low, int high, int key) {
    if(low >= high) {
        return low;
    }

    int mid = low + (high - low) / 2;

    if(arr[mid] > key) {
        high = mid;
    }
    else {
        low = mid + 1;
    }
    
    return upperBound(arr, low, high, key);
}