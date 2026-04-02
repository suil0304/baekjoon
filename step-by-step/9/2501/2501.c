#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int count = 0, num = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            count++;
        }

        if(count == k && num == 0) {
            num = i;
        }
    }
    printf("%d", num);

    return 0;
}