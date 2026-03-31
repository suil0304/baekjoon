#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[4], b[4];
    char ac[4], bc[4];
    scanf("%s %s", a, b);

    strcpy(ac, a);
    strcpy(bc, b);

    for(int i = 0; i < 3; i++) {
        a[i] = ac[2 - i];
        b[i] = bc[2 - i];
    }

    int aint = atoi(a), bint = atoi(b);
    printf("%d", aint > bint ? aint : bint);

    return 0;
}