#include <stdio.h>

int main() {
    int canvas[100][100] = {{0, }, };

    int line;
    scanf("%d", &line);

    for(int i = 0; i < line; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        for(int _x = x; _x < x + 10; _x++) {
            for(int _y = y; _y < y + 10; _y++) {
                canvas[_y][_x] = 1;
            }
        }
    }

    int sum = 0;
    for(int y = 0; y < 100; y++) {
        for(int x = 0; x < 100; x++) {
            sum += canvas[y][x];
        }
    }

    printf("%d", sum);

    return 0;
}