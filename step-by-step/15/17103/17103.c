#include <stdio.h>

int isPrimes[1000001] = {0, };

int main() {
    for(int i = 2; i <= 1000000; i++) {
        isPrimes[i] = 1;
    }

    for(long long i = 2; i * i <= 1000000; i++) {
        if(isPrimes[i]) {
            for(long long j = i * i; j <= 1000000; j += i) {
                isPrimes[j] = 0;
            }
        }
    }

    int t;
    scanf("%d", &t);

    for(int _ = 0; _ < t; _++) {
        int num;
        scanf("%d", &num);

        int count = 0;
        for(int i = 2; i <= num / 2; i++) {
            if(isPrimes[i] && isPrimes[num - i]) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }

    return 0;
}