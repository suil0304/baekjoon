#include <stdio.h>

int main() {
    long long int a, b; // long long int를 사용하래요(long long과 같음)
    scanf("%lld %lld", &a, &b);

    long long base = a;
    long long divde = b;
    while(divde != 0) {
        long long temp = base % divde;
        base = divde;
        divde = temp;
    }

    printf("%lld", (a * b) / base);

    return 0;
}