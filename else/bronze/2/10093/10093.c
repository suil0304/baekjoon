#include <stdio.h>

int main() {
    long long a, b;
    long long start = 0, end = 0;
    scanf("%lld %lld", &a, &b);

    start = a < b ? a : b;
    end = a < b ? b : a;

    printf("%lld\n", start != end ? end - 1 - start : 0);

    for(long long num = start + 1; num < end; num++) {
        printf("%lld ", num);
    }

    return 0;
}