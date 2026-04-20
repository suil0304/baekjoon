#include <stdio.h>

int main() {
    int num = 1;
    while(1) {
        char str[701];
        fgets(str, sizeof(str), stdin);

        if(str[0] == '0') {
            break;
        }

        printf("Case %d: Sorting... done!\n", num);
        num++;
    }

    return 0;
}