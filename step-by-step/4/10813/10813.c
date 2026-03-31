#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* arr;
    arr = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for(int i = 0; i < m; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        int temp = 0;
        temp = arr[start - 1];
        arr[start - 1] = arr[end - 1];
        arr[end - 1] = temp;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}