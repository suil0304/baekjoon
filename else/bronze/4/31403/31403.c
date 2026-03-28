#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a;
    int b;
    int c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    printf("%d\n", a + b - c);

    char strA[9], strB[5];
    sprintf(strA, "%d", a);
    sprintf(strB, "%d", b);
    strcat(strA, strB);

    int result;
    result = atoi(strA);
    printf("%d\n", result - c);

    return 0;
}