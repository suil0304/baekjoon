#include <stdio.h>

int cache[15][15] = {{0, }, }; // 무조건 1 이상의 값이 들어옴 -> 0으로 초기화해도 괜찮다는 소리

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

    if(!cache[floor][room - 1]) {
        cache[floor][room - 1] = recursive(floor, room - 1) + recursive(floor - 1, room);
    }

    return cache[floor][room - 1];
}