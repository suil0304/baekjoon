#include <stdio.h>

int isChecked[1000001] = {0, };

int main() {
    int start, end;
    scanf("%d %d", &start, &end);

    isChecked[0] = 1;
    isChecked[1] = 1;

    for(long long i = 2; i * i <= end; i++) {
        if(isChecked[i] == 0) {
            for(long long j = i * i; j <= end; j += i) {
                isChecked[j] = 1;
            }
        }
    }

    for(int i = start; i <= end; i++) {
        if(isChecked[i] == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}