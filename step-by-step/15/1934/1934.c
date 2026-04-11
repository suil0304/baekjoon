#include <stdio.h>

int euclideanAlgorithm(int base, int divde);

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int gcd = euclideanAlgorithm(a, b);

        printf("%d\n", (a * b) / gcd);
    }

    return 0;
}

int euclideanAlgorithm(int base, int divde) {
    if(divde == 0) {
        return base;
    }
    return euclideanAlgorithm(divde, base % divde);
}