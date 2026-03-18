#include <stdio.h>

int main() {
    int max = 0, index = 0;
    
    for(int i = 0; i < 9; i++) {
        int num;
        scanf("%d", &num);

        if(max < num) {
            max = num;
            index = i + 1;
        }
    }
    printf("%d\n", max);
    printf("%d\n", index);

    return 0;
}