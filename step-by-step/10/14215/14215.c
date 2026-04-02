#include <stdio.h>

#define max(a, b) (\
    (a > b) ? (a) : (b)\
)

#define min(a, b) (\
    (a > b) ? (b) : (a)\
)

int main() {
    int lines[3] = {0, };
    scanf("%d %d %d", &lines[0], &lines[1], &lines[2]);

    int maxLine = max(max(lines[0], lines[1]), lines[2]);
    int sum = 0; // 2 + 5 + 2 = 7
    for(int i = 0; i < 3; i++) {
        sum += lines[i];
    }

    if(maxLine >= (sum - maxLine)) {
        int minLine = min(min(lines[0], lines[1]), lines[2]);
        printf("%d", (sum - maxLine) + (sum - maxLine - 1));
    }
    else {
        printf("%d", sum);
    }

    return 0;
}