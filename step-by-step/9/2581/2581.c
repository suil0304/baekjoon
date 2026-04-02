#include <stdio.h>

int main() {
    int start, end;
    scanf("%d %d", &start, &end);

    int sum = 0;
    int minNum = 9989893;
    for(int s = start; s <= end; s++) {
        for(int num = 1; num < s; num++) {
            if(num + 1 == s) {
                if(minNum > s) {
                    minNum = s;
                }
                sum += s;
                break;
            }

            if(num != 1 && s % num == 0) {
                break;
            }
        }
    }

    if(sum == 0) {
        printf("-1");
    }
    else {
        printf("%d\n", sum);
        printf("%d\n", minNum);
    }

    return 0;
}