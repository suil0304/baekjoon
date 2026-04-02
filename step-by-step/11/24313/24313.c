#include <stdio.h>

#define f(x, slope, constant) (\
    ((slope) * (x) + (constant)) \
)

#define g(x) (\
    (x) \
)

int main() {
    int a1, a0;
    scanf("%d %d", &a1, &a0);

    int c;
    scanf("%d", &c);

    int n0;
    scanf("%d", &n0);

    int fValue = f(n0, a1, a0);
    int gValue = c * g(n0);
    // if(fValue > gValue) {
    //     printf("0");
    //     return 0;
    // }

    // for(int n = n0; n <= 100; n++) {
    //     int fValue = f(n, a1, a0);
    //     int nValue = c * n;
    //     if(fValue > nValue) {
    //         printf("0");
    //         return 0;
    //     }
    // }

    // printf("1");
    printf("%d", (fValue <= gValue && a1 <= c)); // slope check

    return 0;
}