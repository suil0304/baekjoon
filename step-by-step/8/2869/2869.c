#include <stdio.h>
#include <math.h>

int main() {
    double a, b, v;
    scanf("%lf %lf %lf", &a, &b, &v);

    printf("%d", (int) ceil((v - b) / (a - b)));

    return 0;
}