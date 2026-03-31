#include <stdio.h>
#include <string.h>

int main() {
    char strArray[5][16] = {(char) 0, };
    int maxLen = 0;
    for(int i = 0; i < 5; i++) {
        scanf(" %s", strArray[i]);

        int length;
        length = strlen(strArray[i]);
        if(length > maxLen) {
            maxLen = length;
        }
    }

    for(int x = 0; x < 15; x++) {
        if(x >= maxLen) {
            break;
        }

        for(int y = 0; y < 5; y++) {
            if(strArray[y][x] == '\0') {
                continue;
            }
            printf("%c", strArray[y][x]);
        }
        
    }

    return 0;
}