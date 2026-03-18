#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int min = 1000001, max = 0;
    for(int _ = 0; _ < n; _++) {
        int num;
        scanf("%d", &num);

        if(min > num) {
            min = num;
        }
        else if(max < num) {
            max = num;
        }
    }
    printf("%d %d", min, max);

    return 0;
}