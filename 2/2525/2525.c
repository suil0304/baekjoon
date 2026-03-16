#include <stdio.h>

int main() {
    int time, minute;
    int delta;
    scanf("%d %d", &time, &minute);
    scanf("%d", &delta);
    
    minute += delta;
    if(minute >= 60) {
        time += minute / 60;
        if(time >= 24) {
            time = 0;
        }
        minute -= 60 * (minute / 60);
    }
    printf("%d %d", time, minute);

    return 0;
}