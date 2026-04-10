#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
    int aElementNum, bElementNum;
    scanf("%d %d", &aElementNum, &bElementNum);

    int* a;
    a = (int*) malloc(sizeof(int) * aElementNum);

    for(int i = 0; i < aElementNum; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    qsort(a, aElementNum, sizeof(int), compare);

    int sameCount = 0;
    for(int i = 0; i < bElementNum; i++) {
        int element;
        scanf("%d", &element);

        if(bsearch(&element, a, aElementNum, sizeof(int), compare) != NULL) {
            sameCount++;
        }
    }

    printf("%d", (aElementNum - sameCount) + (bElementNum - sameCount));

    free(a);

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}