#include <stdio.h>
#include <string.h>

int main() {
    char str[33] = {'\0', };
    int num, base;
    scanf("%d %d", &num, &base);

    for(int i = 0; num > 0; i++) {
        int _num;
        _num = num % base;
        num /= base;

        char charNum;
        if(_num < 10) {
            charNum = (char) (_num + (int) '0');
        }
        else {
            charNum = (char) (_num - 10 + (int) 'A');
        }
        str[i] = charNum;
    }

    int length;
    length = (int) strlen(str);
    for(int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}