#include <stdio.h>

int main() {
    int memory[246912] = {0, };

    while(1) {
        int num;
        scanf("%d", &num);

        if(num == 0) {
            break;
        }
        else if(num == 1) {
            printf("%d\n", 1);
            continue;
        }

        if(memory[num - 1] > 0)  {
            printf("%d\n", memory[num - 1]);
            continue;
        }

        int count = 0;
        for(int i = num + 1; i <= num * 2; i++) {
            int isPrime = 1;
            for(int j = 2; j * j <= i; j++) {
                if(i % j == 0) {
                   isPrime = 0;
                   break; 
                }
            }

            if(isPrime) {
                count++;
            }
        }

        memory[num - 1] = count;

        printf("%d\n", memory[num - 1]);
    }

    return 0;
}