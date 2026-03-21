#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* scores;
    scores = (int*) calloc(n, sizeof(int));

    float newScore = 0;
    float maxScore = 0;
    for(int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);

        if(score > maxScore) {
            maxScore = score;
        }

        scores[i] = score;
    }

    for(int i = 0; i < n; i++) {
        newScore += scores[i] / maxScore * 100.0;
    }

    newScore /= n;
    printf("%lf", newScore);

    return 0;
}