#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    if(n == 1) {
        printf("0");

        return 0;
    }

    int minX = 100001, maxX = -100001;
    int minY = 100001, maxY = -100001;

    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        if(minX > x) {
            minX = x;
        }
        if(minY > y) {
            minY = y;
        }

        if(maxX < x) {
            maxX = x;
        }
        if(maxY < y) {
            maxY = y;
        }
    }

    int width = abs(maxX - minX);
    int height = abs(maxY - minY);

    printf("%d", width * height);

    return 0;
}