#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int generatorNum = 0;
    for(int i = 1; i < n; i++) {
        char str[8] = "";
        sprintf(str, "%d", i);

        int sum = i;
        int length = (int) strlen(str);
        for(int j = 0; j < length; j++) {
            sum += str[j] - '0';
        }

        if(sum == n) {
            generatorNum = i;
            break;
        }
    }

    printf("%d", generatorNum);

    return 0;
}