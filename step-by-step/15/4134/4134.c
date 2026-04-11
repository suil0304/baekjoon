#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int _ = 0; _ < t; _++) {
        long long num;
        scanf("%lld", &num);

        if(num == 0 || num == 1) {
            printf("%d\n", 2);
            continue;
        }

        long long prime = 0;
        for(long long i = num; i <= num * 2; i++) {
            int isFinded = 1;
            long long sqrtNum = sqrt(i);
            for(int j = 2; j <= sqrtNum; j++) {
                if(i % j == 0) {
                    isFinded = 0;
                    break;
                }
            }

            if(isFinded) {
                prime = i;
                break;
            }
        }

        printf("%lld\n", prime);
    }

    return 0;
}