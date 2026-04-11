#include <stdio.h>

int main() {
    while(1) {
        int boyfriendNum, girlfriendNum;
        scanf("%d %d", &boyfriendNum, &girlfriendNum);

        if(!boyfriendNum && !girlfriendNum) {
            break;
        }

        printf("%d\n", boyfriendNum + girlfriendNum);
    }

    return 0;
}