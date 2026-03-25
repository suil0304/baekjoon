#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    for(int _ = 0; _ < n; _++) {
        char prevChar = ' ';
        int alreadyAlphaChecked[26] = {0, };

        char str[101];
        scanf("%s", str);

        int length = strlen(str);
        for(int i = 0; i < length; i++) {
            int ascii = (int) str[i];
            int toIndex = ascii - 97;

            if(alreadyAlphaChecked[toIndex] && prevChar != str[i]) {
                break;
            }
            else if(i == length - 1) {
                count++;
            }
            else {
                alreadyAlphaChecked[toIndex] = 1;
            }
            prevChar = str[i];
        }
    }
    printf("%d", count);

    return 0;
}