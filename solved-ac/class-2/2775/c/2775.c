#include <stdio.h>

int recursive(int floor, int room);

int main() {
    int t;
    scanf("%d", &t);

    for(int _ = 0; _ < t; _++) {
        int floor;
        scanf("%d", &floor);

        int room;
        scanf("%d", &room);

        printf("%d\n", recursive(floor, room));
    }

    return 0;
}

int recursive(int floor, int room) {
    if(floor == 0) {
        return room;
    }

    if(room == 1) {
        return 1;
    }

    return recursive(floor, room - 1) + recursive(floor - 1, room);
}