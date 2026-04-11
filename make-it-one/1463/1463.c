#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 이게 어떻게 실버 3???

int counts[1000001] = {0, };

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 2; i <= n; i++) {
        counts[i] = counts[i - 1] + 1;

        if(i % 2 == 0) {
            if(counts[i] > counts[i / 2] + 1) {
                counts[i] = counts[i / 2] + 1;
            }
        }

        if(i % 3 == 0) {
            if(counts[i] > counts[i / 3] + 1) {
                counts[i] = counts[i / 3] + 1;
            }
        }
    }

    printf("%d", counts[n]);

    return 0;
}