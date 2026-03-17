#include <stdio.h>

int main() {
    while(1) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(!a && !b) {
            break;
        }

        printf("%d\n", a + b);
    }

    return 0;
}