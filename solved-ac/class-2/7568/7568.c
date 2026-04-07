#include <stdio.h>
#include <stdlib.h>

// 전 브루트 포스 싫어함
// 정렬인 줄 알았네
// 아오
// 백준 풀 때 알고리즘 분류 꼭 확인하세요
// - 수리

typedef struct People {
    int weight;
    int height;
} People;

int main() {
    int n;
    scanf("%d", &n);

    People* people;
    people = (People*) malloc(sizeof(People) * n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &people[i].weight, &people[i].height);
    }

    for(int i = 0; i < n; i++) {
        int rank = 1;
        for(int j = 0; j < n; j++) {
            if(people[j].weight > people[i].weight && people[j].height > people[i].height) {
                rank++;
            }
        }
        printf("%d ", rank);
    }

    free(people);

    return 0;
}