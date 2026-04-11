#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int original = 0;
    for(int num = 1000; num < n; num += 100) {
        int tax = num / 10;
        if(num + tax == n) {
            original = num;
        }
    }

    printf("%d", original);

    return 0;
}