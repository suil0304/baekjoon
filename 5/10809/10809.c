#include <stdio.h>
#include <string.h>

int main() {
    int alphabetIndexs[26] = {0, };
    char str[101];
    scanf(" %s", str);

    int length = (int) strlen(str);

    for(int i = 0; i < 26; i++) {
        alphabetIndexs[i] = -1;
    }

    for(int i = 0; i < length; i++) {
        int ascii = ((int) str[i]) - 97;
        
        if(alphabetIndexs[ascii] == -1) {
            alphabetIndexs[ascii] = i;
        }
    }

    for(int i = 0; i < 26; i++) {
        printf("%d ", alphabetIndexs[i]);
    }

    return 0;
}