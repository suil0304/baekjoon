#include <stdio.h>

int main() {
    while(1) {
        int num1, num2, num3;
        scanf("%d %d %d", &num1, &num2, &num3);

        if(!num1 && !num2 && !num3) {
            break;
        }

        int num1Powered = num1 * num1;
        int num2Powered = num2 * num2;
        int num3Powered = num3 * num3;

        int isRight = (num1Powered + num2Powered == num3Powered) ||
            (num2Powered + num3Powered == num1Powered) ||
            (num3Powered + num1Powered == num2Powered);

        printf("%s\n", isRight ? "right" : "wrong");
    }

    return 0;
}