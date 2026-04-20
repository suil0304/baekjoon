#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int factorialN = 1;
    int factorialNMinusK = 1;
    int factorialK = 1;

    for(int num = 1; num <= n; num++) {
        factorialN *= num;
    }

    for(int num = 1; num <= n - k; num++) {
        factorialNMinusK *= num;
    }

    for(int num = 1; num <= k; num++) {
        factorialK *= num;
    }

    printf("%d", factorialN / (factorialNMinusK * factorialK));

    return 0;
}