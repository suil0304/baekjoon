#include <stdio.h>
#include <stdlib.h>

// Ascending Sort가 더 어렵네
// 도움 받음 - Ascending Sort(Gemini)

int** map;

int size;

void dfsWASDThingieWithChangeNum(int x, int y, int n);

int main() {
    scanf("%d", &size);

    map = (int**) calloc(size, sizeof(int*));
    for(int i = 0; i < size; i++) {
        map[i] = (int*) calloc(size, sizeof(int));

        char* str;
        str = (char*) calloc(size + 1, sizeof(size));

        scanf("%s", str);

        for(int j = 0; j < size; j++) {
            map[i][j] = ((int) str[j]) - 48;
        }
        free(str);
    }

    int count = 0;
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) {
            if(map[y][x] == 1) {
                count++;
                dfsWASDThingieWithChangeNum(x, y, count + 1);
            }
        }
    }

    printf("%d\n", count);

    int* arr;
    arr = (int*) calloc(count, sizeof(int));
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) {
            if(map[y][x] != 0) {
                arr[map[y][x] - 2]++;
            }
        }
    }

    int* alreadyCheckeds;
    alreadyCheckeds = (int*) calloc(count, sizeof(int));
    for(int i = 0; i < count; i++) {
        int minNum = 2147483647;
        int minIndex = -1;

        for(int j = 0; j < count; j++) {
            if(alreadyCheckeds[j] == 0 && arr[j] < minNum) {
                minNum = arr[j];
                minIndex = j;
            }
        }

        if(minIndex != -1) {
            alreadyCheckeds[minIndex] = 1;
            printf("%d\n", minNum);
        }
    }

    for(int i = 0; i < size; i++) {
        free(map[i]);
    }
    free(map);
    free(arr);
    free(alreadyCheckeds);

    return 0;
}

void dfsWASDThingieWithChangeNum(int x, int y, int n) {
    map[y][x] = n;

    if(x > 0 && map[y][x - 1] == 1) { // left
        dfsWASDThingieWithChangeNum(x - 1, y, n);
    }
    if(y + 1 <= size - 1 && map[y + 1][x] == 1) { // down
        dfsWASDThingieWithChangeNum(x, y + 1, n);
    }
    if(y > 0 && map[y - 1][x] == 1) { // up
        dfsWASDThingieWithChangeNum(x, y - 1, n);
    }
    if(x + 1 <= size - 1 && map[y][x + 1] == 1) { // right
        dfsWASDThingieWithChangeNum(x + 1, y, n);
    }
}