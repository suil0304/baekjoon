#include <stdio.h>
#include <stdlib.h>

int selectMaxNum(int arr[]) {
    int maxNum = 0;
    int length = sizeof arr / sizeof arr[0];

    for(int i = 0; i < length; i++) {
        if(maxNum < arr[i]) {
            maxNum = arr[i];
        }
    }
    
    return maxNum;
}

int main() {
    int dices[3];
    scanf("%d %d %d", &dices[0], &dices[1], &dices[2]);

    if(dices[0] == dices[1] && dices[1] == dices[2]) {
        printf("%d", 10000 + dices[0] * 1000);
    }
    else if(dices[0] == dices[1] || dices[1] == dices[2] || dices[0] == dices[2]) {
        int maxNum = selectMaxNum(dices);
        printf("%d", 1000 + maxNum * 100);
    }
    else {
        int maxNum = selectMaxNum(dices);
        printf("%d", maxNum * 100);
    }

    return 0;
}