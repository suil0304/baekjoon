#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    int x, y;
    for(x = -999; x <= 999; x++) {
        int checked = 0;
        for(y = -999; y <= 999; y++) {
            if((a * x + b * y == c) && (d * x + e * y == f)) {
                checked = 1;
                break;
            }
        }

        if(checked) {
            break;
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}