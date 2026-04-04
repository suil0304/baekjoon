#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    char str[11] = "";
    char devilNumStr[4] = "666";

    int count = 0;
    int resultDevilNum = 0;
    for(int i = 666; i < INT_MAX; i++) {
        sprintf(str, "%d", i);
        if(strstr(str, devilNumStr)) {
            count++;
        }
        
        if(count == n) {
            resultDevilNum = i;
            break;
        }
    }

    printf("%d", resultDevilNum);

    return 0;
}