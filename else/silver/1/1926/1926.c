#include <stdio.h>
#include <stdlib.h>

int height, width;
int** painting;

int maxPaintingSize = 0;
int curPaintingSize = 0;

void dfsWASDThingie(int x, int y);

int main() {
    scanf("%d %d", &height, &width);

    painting = (int**) calloc(height, sizeof(int*));

    for(int i = 0; i < height; i++) {
        painting[i] = (int*) calloc(width, sizeof(int));
    }

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            scanf("%d", &painting[y][x]);
        }
    }

    int paintingCount = 0;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(painting[y][x] == 1) {
                paintingCount++;

                curPaintingSize = 0;
                dfsWASDThingie(x, y);
                if(maxPaintingSize < curPaintingSize) {
                    maxPaintingSize = curPaintingSize;
                }
            }
        }
    }

    printf("%d\n", paintingCount);
    printf("%d\n", maxPaintingSize);

    for(int i = 0; i < height; i++) {
        free(painting[i]);
    }
    free(painting);
    
    return 0;
}

void dfsWASDThingie(int x, int y) {
    painting[y][x] = 0;
    curPaintingSize++;
    if(x > 0 && painting[y][x - 1] == 1) { // left
        dfsWASDThingie(x - 1, y);
    }
    if(y + 1 <= height - 1 && painting[y + 1][x] == 1) { // down
        dfsWASDThingie(x, y + 1);
    }
    if(y > 0 && painting[y - 1][x] == 1) { // up
        dfsWASDThingie(x, y - 1);
    }
    if(x + 1 <= width - 1 && painting[y][x + 1] == 1) { // right
        dfsWASDThingie(x + 1, y);
    }
}