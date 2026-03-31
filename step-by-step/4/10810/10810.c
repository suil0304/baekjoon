#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* arr;
    arr = (int*) calloc(sizeof(int), n);

    for(int _ = 0; _ < m; _++) {
        int start, end, ball;
        scanf("%d %d %d", &start, &end, &ball);

        for(int i = start - 1; i < end; i++) {
            arr[i] = ball;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}