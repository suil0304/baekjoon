#include <stdio.h>

int main() {
    int time, minute;
    scanf("%d %d", &time, &minute);
    
    minute -= 45;
    if(minute < 0) {
        time--;
        if(time < 0) {
            time = 23;
        }
        minute += 60;
    }
    printf("%d %d", time, minute);

    return 0;
}