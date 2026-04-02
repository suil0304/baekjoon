#include <stdio.h>
#include <math.h>

int main() {
    while(1) {
        float a, b;
        scanf("%f %f", &a, &b);

        if(a == 0 && b == 0) {
            break;
        }

        if((int) b % (int) a == 0) {
            printf("factor\n");
        }
        else if(a / b == round(a / b)) {
            printf("multiple\n");
        }
        else {
            printf("neither\n");
        }
    }

    return 0;
}