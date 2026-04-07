#include <stdio.h>
#include <stdlib.h>

int main() {
    int length;
    scanf("%d", &length);

    char* strAa;
    strAa = (char*) calloc(length + 1, sizeof(char));
    strAa[0] = 'A';
    strAa[1] = 'a';

    char* strBB;
    strBB = (char*) calloc(length + 1, sizeof(char));
    strBB[0] = 'B';
    strBB[1] = 'B';

    for(int i = 2; i < length; i++) {
        strAa[i] = 'w';
        strBB[i] = 'w';
    }

    printf("%s\n", strAa);
    printf("%s\n", strBB);

    return 0;
}