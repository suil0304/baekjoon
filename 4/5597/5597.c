#include <stdio.h>

int main() {
    int students[30];
    for(int i = 0; i < 28; i++) {
        int curNum;
        scanf("%d", &curNum);
        students[curNum - 1] = 1;
    }

    for(int i = 0; i < 30; i++) {
        if(!students[i]) {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}