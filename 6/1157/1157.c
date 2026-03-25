#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int asciiCounts[26] = {0, };

    char str[1000001];
    scanf("%s", str);

    int length;
    length = strlen(str);

    for(int i = 0; i < length; i++) {
        char character = str[i];
        char uppered = (char) toupper((int) character);
        asciiCounts[((int) uppered) - 65]++;

        str[i] = uppered;
    }

    int maxIndex = 0;
    int maxCount = -1;
    char result = '?';
    for(int i = 0; i < 26; i++) {
        if(maxCount < asciiCounts[i]) {
            maxCount = asciiCounts[i];
            maxIndex = i;
            result = (char) (maxIndex + 65);
        }        
        else if(maxCount == asciiCounts[i]) {
            result = '?';
        }
    }
    printf("%c", result);

    return 0;
}