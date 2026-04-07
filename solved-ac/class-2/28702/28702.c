#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num = -1;
    for(int i = 0; i < 3; i++) {
        char str[9];
        scanf("%s", str);

        if(num != -1) {
            num++;
        }
        else if(strstr(str, "Fizz") == NULL && strstr(str, "Buzz") == NULL) {
            char* endPtr;
            num = (int) strtol(str, &endPtr, 10);
        }
    }

    num++;

    if(num % 3 == 0 && num % 5 == 0) {
        printf("FizzBuzz");
    }
    else if(num % 3 == 0) {
        printf("Fizz");
    }
    else if(num % 5 == 0) {
        printf("Buzz");
    }
    else {
        printf("%d", num);
    }

    return 0;
}