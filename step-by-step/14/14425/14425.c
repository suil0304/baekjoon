#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);

int main() {
    int n, queryNum;
    scanf("%d %d", &n, &queryNum);

    char (*strArray)[501] = malloc(sizeof(*strArray) * n);

    for(int i = 0; i < n; i++) {
        scanf("%s", strArray[i]);
    }

    qsort(strArray, n, sizeof(*strArray), compare);

    int count = 0;
    for(int i = 0; i < queryNum; i++) {
        char queryStr[501];
        scanf("%s", queryStr);

        if(bsearch(queryStr, strArray, n, sizeof(*strArray), compare) != NULL) {
            count++;
        }
    }

    printf("%d", count);

    free(strArray);

    return 0;
}

int compare(const void* a, const void* b) {
    return strcmp((char*) a, (char*) b);
}