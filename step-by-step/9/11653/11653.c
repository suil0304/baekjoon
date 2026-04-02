#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int divde = 2; n != 1; divde++) {
        for(int j = 0; n % divde == 0; j++) {
            printf("%d\n", divde);
            n /= divde;
        }
    }

    return 0;
}