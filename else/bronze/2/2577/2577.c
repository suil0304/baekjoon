#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    long long result = (long long) (a * b * c);
    int counts[10] = {0, };

    while(result > 0) {
        int digit = result % 10;
        counts[digit]++;
        result /= 10;
    }

    for(int i = 0; i < 10; i++) {
        printf("%d\n", counts[i]);
    }

    return 0;
}