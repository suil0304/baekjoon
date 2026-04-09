#include <stdio.h>
#include <stdlib.h>

typedef struct People {
    char name[101];
    int age;
    int index;
} People;

int compare(const void* a, const void* b);

int main() {
    int n;
    scanf("%d", &n);

    People* people;
    people = (People*) malloc(sizeof(People) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d %s", &people[i].age, people[i].name);
        people[i].index = i;
    }

    qsort(people, n, sizeof(People), compare);

    for(int i = 0; i < n; i++) {
        printf("%d %s\n", people[i].age, people[i].name);
    }

    free(people);

    return 0;
}

int compare(const void* a, const void* b) {
    if(((People*) a)->age != ((People*) b)->age) {
        return ((People*) a)->age - ((People*) b)->age;
    }
    return ((People*) a)->index - ((People*) b)->index;
}