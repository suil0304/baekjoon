#include <stdio.h>

int main() {
    int xPoints[3] = {0, };
    int yPoints[3] = {0, };

    scanf("%d %d %d %d %d %d", &xPoints[0], &yPoints[0], &xPoints[1], &yPoints[1], &xPoints[2], &yPoints[2]);

    if(xPoints[0] == xPoints[1]) {
        printf("%d ", xPoints[2]);
    }
    else if(xPoints[1] == xPoints[2]) {
        printf("%d ", xPoints[0]);
    }
    else {
        printf("%d ", xPoints[1]);
    }

    if(yPoints[0] == yPoints[1]) {
        printf("%d", yPoints[2]);
    }
    else if(yPoints[1] == yPoints[2]) {
        printf("%d", yPoints[0]);
    }
    else {
        printf("%d", yPoints[1]);
    }

    return 0;
}