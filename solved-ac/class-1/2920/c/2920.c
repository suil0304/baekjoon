#include <stdio.h>

int main() {
    int isAscending = 1;
    int isDescending = 1;

    int prev = 0;
    for(int i = 0; i < 8; i++) {
        int num;
        scanf("%d", &num);

        if(prev != 0 && prev + 1 != num) {
            isAscending = 0;
        }
        if(prev != 0 && prev - 1 != num) {
            isDescending = 0;
        }
        prev = num;
    }

    if(isAscending) {
        printf("%s", "ascending");
    }
    else if(isDescending) {
        printf("%s", "descending");
    }
    else {
        printf("%s", "mixed");
    }

    return 0;
}