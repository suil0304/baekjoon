#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 1000001

char* ltrim(char* str) {
    char* start;
    start = str;
    while(*start != '\0') {
        if(isspace(*start)) {
            start++;
        }
        else {
            str = start;
            break;
        }
    }
    return str;
}

char* rtrim(char* str) {
    if (str == NULL || *str == '\0') return str;

    char* end;
    end = str + strlen(str) - 1;
    while(end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char* trim(char* str) {
    return rtrim(ltrim(str));
}

int main() {
    char str[MAX_STR_LEN];
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    int token = 1;
    char* trimed = trim(str);
    int trimedLength = (int) strlen(trimed);

    if(!trimedLength) {
        printf("%d", 0);
        return 0;
    }
    
    for(int i = 0; i < trimedLength; i++) {
        if(trimed[i] == ' ') {
            token++;
        }
    }

    printf("%d", token);

    return 0;
}