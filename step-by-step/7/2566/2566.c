#include <stdio.h>

int main() {
    int maxNum = -1;
    int maxY = 0;
    int maxX = 0;
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            int num;
            scanf("%d", &num);

            if(num > maxNum) {
                maxNum = num;
                maxY = y + 1;
                maxX = x + 1;
            }
        }
    }

    printf("%d\n", maxNum);
    printf("%d %d\n", maxY, maxX);

    return 0;
}