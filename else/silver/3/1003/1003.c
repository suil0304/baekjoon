#include <stdio.h>

int zeroArray[41] = {0, };
int oneArray[41] = {0, };

int main() {
    int n;
    scanf("%d", &n);

    zeroArray[0] = 1;
    zeroArray[1] = 0;
    oneArray[0] = 0;
    oneArray[1] = 1;

    for(int i = 2; i <= 40; i++) {
        zeroArray[i] = zeroArray[i - 1] + zeroArray[i - 2];
        oneArray[i] = oneArray[i - 1] + oneArray[i - 2];
    }

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        printf("%d %d\n", zeroArray[num], oneArray[num]);
    }

    return 0;
}