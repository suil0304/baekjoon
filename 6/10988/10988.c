#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[101];
    scanf(" %s", str);
    
    int length = (int) strlen(str);

    char* reversed;
    reversed = (char*) calloc(length + 1, sizeof(char));

    for(int i = 0; i < length; i++) {
        reversed[i] = str[(length - 1) - i];
    }

    printf("%d\n", !!strcmp(str, reversed) ? 0 : 1);
    
    return 0;
}