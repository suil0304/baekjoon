#include <stdio.h>

int main() {
    while(1) {
        int n;
        scanf("%d", &n);

        if(n == -1) {
            break;
        }

        int sum = 0;
        int index = 0;
        int nums[128] = {0, };
        for(int num = 1; num <= n / 2; num++) {
            if(n % num == 0) {
                sum += num;
                nums[index] = num;
                index++;
            }
        }

        if(n != sum) {
            printf("%d is NOT perfect.\n", n);
        }
        else {
            printf("%d = %d", n, nums[0]);
            for(int i = 1; nums[i] != 0; i++) {
                printf(" + %d", nums[i]);
            }
            printf("\n");
        }
    }

    return 0;
}