#include <stdio.h>

int main() {
    long x;
    scanf("%ld", &x);

    int floor = 0;
    for(long i = 1; x - i > 0; i++) {
        x -= i;
        floor++;
    }

    long first, second;
    if(floor % 2 == 0) {
        first = floor - x + 2;
        second = x;
    }
    else {
        first = x;
        second = floor - x + 2;
    }
    printf("%ld/%ld\n", first, second);

    return 0;
}