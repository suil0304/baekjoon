#include <stdio.h>
#include <stdlib.h>

#define r 31ll
#define m 1234567891ll

int main() {
    int length;
    scanf("%d", &length);

    long long sum = 0;
    long long power = 1;
    for(int i = 0; i < length; i++) {
        char c;
        scanf(" %c", &c);

        sum = (sum + ((c - 'a' + 1) * power)) % m;
        power = (power * r) % m;
    }

    printf("%lld", sum);

    return 0;
}