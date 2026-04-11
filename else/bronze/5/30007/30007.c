#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int coefficient, baseWater, boilRamen;
        scanf("%d %d %d", &coefficient, &baseWater, &boilRamen);

        printf("%d\n", coefficient * (boilRamen - 1) + baseWater);
    }

    return 0;
}