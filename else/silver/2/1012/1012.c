#include <stdio.h>
#include <stdlib.h>

int** map;

int curMapWidth;
int curMapHeight;

void dfsWASDThingie(int x, int y);

int main() {
    int testcase;
    scanf("%d", &testcase);

    while(testcase) {
        int count = 0;
        
        int cabbages;
        scanf("%d %d %d", &curMapWidth, &curMapHeight, &cabbages);

        map = (int**) calloc(curMapHeight, sizeof(int*));
        for(int i = 0; i < curMapHeight; i++) {
            map[i] = (int*) calloc(curMapWidth, sizeof(int));
        }

        for(int i = 0; i < cabbages; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            map[y][x] = 1;
        }

        for(int y = 0; y < curMapHeight; y++) {
            for(int x = 0; x < curMapWidth; x++) {
                if(map[y][x] == 1) {
                    count++;
                    dfsWASDThingie(x, y);
                }
            }
        }

        printf("%d\n", count);

        for(int i = 0; i < curMapHeight; i++) {
            free(map[i]);
        }
        free(map);

        testcase--;
    }

    return 0;
}

void dfsWASDThingie(int x, int y) {
    map[y][x] = 0;
    if(x > 0 && map[y][x - 1] == 1) { // left
        dfsWASDThingie(x - 1, y);
    }
    if(y + 1 <= curMapHeight - 1 && map[y + 1][x] == 1) { // down
        dfsWASDThingie(x, y + 1);
    }
    if(y > 0 && map[y - 1][x] == 1) { // up
        dfsWASDThingie(x, y - 1);
    }
    if(x + 1 <= curMapWidth - 1 && map[y][x + 1] == 1) { // right
        dfsWASDThingie(x + 1, y);
    }
}