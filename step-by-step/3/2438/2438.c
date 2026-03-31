#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n + 1; i++) {
        for(int _ = 0; _ < i; _++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}