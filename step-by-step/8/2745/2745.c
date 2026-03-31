#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char str[33];
    int base;
    scanf(" %s %d", str, &base);

    int length;
    length = strlen(str);

    int sum = 0;
    for(int i = length - 1; i >= 0; i--) {
        int addNum = 0;
        if(str[i] >= (int) '0' && str[i] <= (int) '9') {
            addNum = ((int) str[i] - (int) '0') * pow(base, length - (i + 1));
        }
        else if(str[i] >= (int) 'A' && str[i] <= (int) 'Z') {
            addNum = ((int) str[i] - (int) 'A' + 10) * pow(base, length - (i + 1));
        }
        sum += addNum;
    }
    printf("%d", sum);

    return 0;
}