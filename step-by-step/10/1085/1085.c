#include <stdio.h>

int main() {
    int x, y, width, height;
    scanf("%d %d %d %d", &x, &y, &width, &height);

    int distanceX = width / 2 < x ? width - x : x;
    int distanceY = height / 2 < y ? height - y : y;
    if(distanceX < distanceY) {
        printf("%d", distanceX);
    }
    else {
        printf("%d", distanceY);
    }

    return 0;
}