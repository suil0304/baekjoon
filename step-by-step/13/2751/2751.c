#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int counts[2000001] = {0, };

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        counts[num + 1000000]++;
    }

    for(int i = 0; i < 2000001; i++) {
        if(counts[i] != 0) {
            printf("%d\n", i - 1000000);
        }
    }

    return 0;
}