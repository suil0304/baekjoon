#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int _ = 0; _ < t; _++) {
        int repeat;
        char str[21];
        scanf("%d %s", &repeat, str);

        int length = (int) strlen(str);

        char* repeatedStr;
        repeatedStr = (char*) calloc((length * repeat) + 1, sizeof(char));

        for(int i = 0; i < length; i++) {
            for(int j = 0; j < repeat; j++) {
                repeatedStr[(repeat * i) + j] = str[i];
            }
        }

        printf("%s\n", repeatedStr);

        free(repeatedStr);
    }

    return 0;
}