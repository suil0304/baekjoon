#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf(" %s", str);
    printf("%d", (int) strlen(str));

    return 0;
}