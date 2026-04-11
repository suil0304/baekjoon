#include <stdio.h>

int counts[1000001] = {0, };
int tracking[1000001] = {0, };

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 1) {
        printf("%d\n", 0);
        printf("%d\n", 1);

        return 0;
    }

    for(int i = 2; i <= n; i++) {
        counts[i] = counts[i - 1] + 1;
        tracking[i] = i - 1;

        if(i % 2 == 0) {
            if(counts[i] > counts[i / 2]) {
                counts[i] = counts[i / 2] + 1;
                tracking[i] = i / 2;
            }
        }

        if(i % 3 == 0) {
            if(counts[i] > counts[i / 3]) {
                counts[i] = counts[i / 3] + 1;
                tracking[i] = i / 3;
            }
        }
    }

    printf("%d\n", counts[n]);

    int cur = n;
    while(cur != 0) {
        printf("%d ", cur);
        if(cur == 1) {
            break;
        }
        cur = tracking[cur];
    }

    return 0;
}