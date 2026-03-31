#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int _ = 0; _ < n / 4; _++) {
        printf("long ");
    }
    printf("int");

    return 0;
}