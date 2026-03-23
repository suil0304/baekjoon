#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    char *str;
    str = (char*) malloc(sizeof(char) * (n + 1));
    scanf(" %s", str);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (((int) str[i]) - 48);
    }

    printf("%d\n", sum);

    free(str);

    return 0;
}