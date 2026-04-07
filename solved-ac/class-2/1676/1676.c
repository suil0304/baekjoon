#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int zeroCount = 0;
    for(int i = 5; n / i >= 1; i *= 5) {
        zeroCount += (n / i);
    }

    printf("%d\n", zeroCount);

    return 0;
}