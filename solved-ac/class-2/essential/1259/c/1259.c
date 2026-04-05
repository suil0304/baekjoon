#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    while(1) {
        char str[6];
        scanf("%s", str);

        if(str[0] == '0') {
            break;
        }

        int length = (int) strlen(str);

        char* reversed;
        reversed = (char*) calloc(length + 1, sizeof(char));

        for(int i = 0; i < length; i++) {
            reversed[length - 1 - i] = str[i];
        }

        printf("%s\n", strcmp(str, reversed) == 0 ? "yes" : "no");

        free(reversed);
    }

    return 0;
}