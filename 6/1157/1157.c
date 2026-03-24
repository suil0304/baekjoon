#include <stdio.h>
#include <string.h>

// 컴파일 에러는 뭐야

/*

------------------------------------------------------
오류
에러 유형: 제출 코드 컴파일 에러(TargetCompilationFailed)
메세지:
Main.c: In function ‘main’:
Main.c:11:13: warning: implicit declaration of function ‘strupr’; did you mean ‘strstr’? [-Wimplicit-function-declaration]
   11 |     upper = strupr(str);
      |             ^~~~~~
      |             strstr
Main.c:11:11: warning: assignment to ‘char *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
   11 |     upper = strupr(str);
      |           ^
Main.c:8:5: warning: ignoring return value of ‘scanf’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
    8 |     scanf("%s", str);
      |     ^~~~~~~~~~~~~~~~
/usr/bin/ld: /tmp/ccnUHElk.o: in function `main':
Main.c:(.text.startup+0x61): undefined reference to `strupr'
collect2: error: ld returned 1 exit status
------------------------------------------------------

일단 VScode에서는 정상 작동함
아마도
음

*/

int main() {
    int asciiCounts[26] = {0, };

    char str[1000001];
    scanf("%s", str);

    char* upper;
    upper = strupr(str);

    int length;
    length = strlen(upper);

    for(int i = 0; i < length; i++) {
        char character = upper[i];
        asciiCounts[((int) character) - 65]++;
    }

    int maxIndex = 0;
    for(int i = 0; i < 26; i++) {
        if(asciiCounts[maxIndex] < asciiCounts[i]) {
            maxIndex = i;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(asciiCounts[maxIndex] == asciiCounts[i] && maxIndex != i) {
            printf("?");
            return 0;
        }
    }
    printf("%c", (char) (65 + maxIndex));

    return 0;
}