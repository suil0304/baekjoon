#include <stdio.h>
#include <stdlib.h>

int compareNum(const void* a, const void* b);

int main() {
    int n, minPrizeScoreIndex;
    scanf("%d %d", &n, &minPrizeScoreIndex);

    int* scores;
    scores = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);

        scores[i] = score;
    }

    qsort(scores, n, sizeof(int), compareNum);

    printf("%d", scores[minPrizeScoreIndex - 1]);

    free(scores);

    return 0;
}

int compareNum(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}