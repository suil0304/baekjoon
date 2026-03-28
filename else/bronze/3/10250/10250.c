#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        int width, height, nth;
        scanf("%d %d %d", &height, &width, &nth);

        int floor;
        floor = nth % height;

        int room;
        room = (nth / height) + 1;
        if(floor == 0) {
            floor = height;
            room = nth / height;
        }
        printf("%d%02d\n", floor, room);
    }

    return 0;
}