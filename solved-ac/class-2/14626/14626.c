#include <stdio.h>

int main() {
    int sum = 0;
    int brokenIndex = 0;
    for(int i = 0; i < 13; i++) {
        char c;
        scanf(" %c", &c);

        if(c == '*') {
            brokenIndex = i;
            continue;
        }

        sum += (c - '0') * ((i + 1) % 2 == 0 ? 3 : 1);
    }

    int num = 0;
    int mult = (brokenIndex + 1) % 2 == 0 ? 3 : 1;
    for(int i = 1; i < 10; i++) {
        if((sum + (i * mult)) % 10 == 0) {
            num = i;
        }
    }

    printf("%d", num);

    return 0;
}