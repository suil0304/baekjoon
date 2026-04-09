#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareNum(const void* a, const void* b);

int main() {
    int n;
    scanf("%d", &n);

    char (*strArray)[51] = malloc(sizeof(*strArray) * n);
    for(int i = 0; i < n; i++) {
        scanf("%s", strArray[i]);
    }

    qsort(strArray, n, sizeof(*strArray), compareNum);

    char prev[51] = {0, };
    for(int i = 0; i < n; i++) {
        if(strcmp(strArray[i], prev) != 0) {
            printf("%s\n", strArray[i]);
        }
        strcpy(prev, strArray[i]);
    }

    free(strArray);

    return 0;
}

int compareNum(const void* a, const void* b) {
    int lengthA = (int) strlen((char*) a);
    int lengthB = (int) strlen((char*) b);

    if(lengthA != lengthB) {
        return lengthA - lengthB;
    }

    return strcmp((char*) a, (char*) b);
}