#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int count = 0;
    for(int i = 0; i < t; i++) {
        int num;
        scanf("%d", &num);

        for(int j = 1; j < num; j++) {
            if(j + 1 == num) {
                count++;
                break;
            }

            if(j != 1 && num % j == 0) {
                break;
            }
        }
    }
    printf("%d", count);

    return 0;
}