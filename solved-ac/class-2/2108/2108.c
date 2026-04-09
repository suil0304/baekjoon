#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct CountWithNum {
    int count;
    int num;
} CountWithNum;

int compareNum(const void* a, const void* b);
int compareCount(const void* a, const void* b);

int main() {
    int n;
    scanf("%d", &n);

    int* nums;
    nums = (int*) malloc(sizeof(int) * n);

    int countNumOnlyArray[8001] = {0, };
    double sum = 0;
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        sum += num;

        nums[i] = num;
        countNumOnlyArray[num + 4000]++;
    }

    int existNum = 0;
    for(int i = 0; i < 8001; i++) {
        if(countNumOnlyArray[i]) {
            existNum++;
        }
    }

    CountWithNum* countNumArray;
    countNumArray = (CountWithNum*) malloc(sizeof(CountWithNum) * existNum);

    int countIndex = 0;
    for(int i = 0; i < 8001; i++) {
        if(countNumOnlyArray[i]) {
            countNumArray[countIndex].num = i - 4000;
            countNumArray[countIndex].count = countNumOnlyArray[i];

            countIndex++;
        }
    }

    qsort(nums, n, sizeof(int), compareNum);
    qsort(countNumArray, existNum, sizeof(CountWithNum), compareCount);

    sum /= n;
    printf("%d\n", (int) round(sum)); // 1

    printf("%d\n", nums[n / 2]); // 2

    if(existNum > 1 && (countNumArray[0].count == countNumArray[1].count)) {
        printf("%d\n", countNumArray[1].num); // 3
    }
    else {
        printf("%d\n", countNumArray[0].num); // 3
    }

    printf("%d\n", nums[n - 1] - nums[0]); // 4

    free(countNumArray);

    return 0;
}

int compareNum(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int compareCount(const void* a, const void* b) {
    if(((CountWithNum*) a)->count == ((CountWithNum*) b)->count) {
        return ((CountWithNum*) a)->num - ((CountWithNum*) b)->num;
    }
    return ((CountWithNum*) b)->count - ((CountWithNum*) a)->count;
}