#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2 = 0;
    char num2Str[4];
    scanf("%d", &num1);
    scanf("%s", num2Str);

    printf("%d\n", num1 * ((int)(num2Str[0]) - 48));
    printf("%d\n", num1 * ((int)(num2Str[1]) - 48));
    printf("%d\n", num1 * ((int)(num2Str[2]) - 48));

    num2 = atoi(num2Str);

    printf("%d\n", num1 * num2);

    return 0;
}