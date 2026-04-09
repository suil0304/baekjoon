#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compareNum(const void* a, const void* b);

int main() {
    int n;
    scanf("%d", &n);

    if(n == 0) {
        printf("0");
        return 0;
    }

    int* ranks;
    ranks = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        int rank;
        scanf("%d", &rank);

        ranks[i] = rank;
    }

    qsort(ranks, n, sizeof(int), compareNum);

    int trimNum = (int) round(n * .15);

    double sum = 0;
    for(int i = trimNum; i < (n - trimNum); i++) {
        sum += ranks[i];
    }
    sum = round(sum / (n - (trimNum * 2)));

    printf("%.0lf", sum);

    free(ranks);

    return 0;
}

int compareNum(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}