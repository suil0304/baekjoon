#include <stdio.h>
#include <stdlib.h>

int main() {
    int height, width;
    scanf("%d %d", &height, &width);

    int** a;
    a = (int**) calloc(height, sizeof(int*));

    for(int i = 0; i < height; i++) {
        a[i] = (int*) calloc(width, sizeof(int));
    }

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            scanf("%d", &a[y][x]);
        }
    }

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int num;
            scanf("%d", &num);

            a[y][x] += num;
            printf("%d ", a[y][x]);
        }
        printf("\n");
    }

    for(int i = 0; i < height; i++) {
        free(a[i]);
    }

    free(a);

    return 0;
}