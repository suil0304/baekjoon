#include <stdio.h>
#include <string.h>

int main() {
    int cur = 0;
    int curAdd = 0;

    int num;
    scanf("%d", &num);

    char str[81];
    for(int i = 0; i < num; i++) {
        scanf("%s", str);

        int length;
        length = strlen(str);

        for(int j = 0; j < length; j++) {
            if(str[j] == 'O') {
                curAdd++;
            }
            else {
                curAdd = 0;
            }
            cur += curAdd;
        }
        printf("%d\n", cur);
        cur = 0;
        curAdd = 0;
    }

    return 0;
}