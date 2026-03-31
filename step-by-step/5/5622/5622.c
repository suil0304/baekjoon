#include <stdio.h>
#include <string.h>

#define NUMBER_ONE_TIME_NEEDS 2

int main() {
    char str[16];
    scanf(" %s", str);

    int length = strlen(str);
    int totalTime = 0;
    for(int i = 0; i < length; i++) {
        int ascii = (int) str[i];
        if(ascii - 87 >= 0) { // 9
            totalTime += 10;
        }
        else if(ascii - 84 >= 0) { // 8
            totalTime += 9;
        }
        else if(ascii - 80 >= 0) { // 7
            totalTime += 8;
        }
        else if(ascii - 77 >= 0) { // 6
            totalTime += 7;
        }
        else if(ascii - 74 >= 0) { // 5
            totalTime += 6;
        }
        else if(ascii - 71 >= 0) { // 4
            totalTime += 5;
        }
        else if(ascii - 68 >= 0) { // 3
            totalTime += 4;
        }
        else if(ascii - 65 >= 0) { // 2
            totalTime += 3;
        }
    }

    printf("%d", totalTime);

    return 0;
}