#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int _ = 0; _ < t; _++) {
        char str[1001];
        scanf(" %s", str);

        int lastIndex = ((int) strlen(str)) - 1;
        printf("%c%c\n", str[0], str[lastIndex]);
    }

    return 0;
}