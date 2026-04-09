#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int counts[10000] = {0, };

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        counts[num - 1]++;
    }

    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < counts[i]; j++) {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}