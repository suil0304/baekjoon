#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pokemon {
    char name[21];
    int pokeno;
} Pokemon;

int compare(const void* a, const void* b);

int main() {
    int n, queryNum;
    scanf("%d %d", &n, &queryNum);

    char (*pokemonNormalArray)[21] = malloc(sizeof(*pokemonNormalArray) * n);

    Pokemon* pokemonNameArray;
    pokemonNameArray = (Pokemon*) malloc(sizeof(Pokemon) * n);

    for(int i = 0; i < n; i++) {
        char str[21];
        scanf("%s", str);

        strcpy(pokemonNormalArray[i], str);
        strcpy(pokemonNameArray[i].name, str);
        pokemonNameArray[i].pokeno = i;
    }

    qsort(pokemonNameArray, n, sizeof(Pokemon), compare);

    for(int i = 0; i < queryNum; i++) {
        char str[21];
        scanf("%s", str);

        if(str[0] >= '1' && str[0] <= '9') {
            int index = atoi(str) - 1;
            printf("%s\n", pokemonNormalArray[index]);
        }
        else {
            Pokemon pokemon = *(Pokemon*) bsearch(str, pokemonNameArray, n, sizeof(Pokemon), compare);
            printf("%d\n", pokemon.pokeno + 1);
        }
    }

    free(pokemonNormalArray);
    free(pokemonNameArray);

    return 0;
}

int compare(const void* a, const void* b) {
    return strcmp(((Pokemon*) a)->name, ((Pokemon*) b)->name);
}