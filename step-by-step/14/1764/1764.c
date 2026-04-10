#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (\
    (a > b) ? (a) : (b) \
)

int compare(const void* a, const void* b);

int main() {
    int notListeningNum, notSeeingNum;
    scanf("%d %d", &notListeningNum, &notSeeingNum);

    char (*notListeningPeople)[21] = malloc(sizeof(*notListeningPeople) * notListeningNum);

    for(int i = 0; i < notListeningNum; i++) {
        scanf(" %s", notListeningPeople[i]);
    }

    qsort(notListeningPeople, notListeningNum, sizeof(*notListeningPeople), compare);

    char (*notListenNotSeePeople)[21] = malloc(sizeof(*notListenNotSeePeople) * max(notListeningNum, notSeeingNum));
    int length = 0;
    for(int i = 0; i < notSeeingNum; i++) {
        char str[21];
        scanf(" %s", str);

        if(bsearch(str, notListeningPeople, notListeningNum, sizeof(*notListeningPeople), compare) != NULL) {
            strcpy(notListenNotSeePeople[length], str);
            length++;
        }
    }

    realloc(notListenNotSeePeople, sizeof(*notListenNotSeePeople) * length);

    qsort(notListenNotSeePeople, length, sizeof(*notListenNotSeePeople), compare);

    printf("%d\n", length);
    for(int i = 0; i < length; i++) {
        printf("%s\n", notListenNotSeePeople[i]);
    }

    free(notListeningPeople);
    free(notListenNotSeePeople);

    return 0;
}

int compare(const void* a, const void* b) {
    return strcmp((char*) a, (char*) b);
}