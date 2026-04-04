#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (\
    (a > b) ? (a) : (b) \
)

#define min(a, b) (\
    (a < b) ? (a) : (b) \
)

int main() {
    int height, width;
    scanf("%d %d", &height, &width);

    char** strArray;
    strArray = (char**) calloc(height, sizeof(char*));
    for(int i = 0; i < height; i++) {
        strArray[i] = (char*) calloc(width + 1, sizeof(char));
        scanf("%s", strArray[i]);
    }

    char chessboardWhite[8][9] = {"", };
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            chessboardWhite[y][x] = (x + y) % 2 == 0 ? 'W' : 'B';
        }
    }

    int fixCount = 64;
    for(int y = 0; y <= height - 8; y++) {
        for(int x = 0; x <= width - 8; x++) {
            int whiteboardCount = 0;
            for(int chessY = 0; chessY < 8; chessY++) {
                for(int chessX = 0; chessX < 8; chessX++) {
                    if(strArray[y + chessY][x + chessX] != chessboardWhite[chessY][chessX]) {
                        whiteboardCount++;
                    }
                }
            }

            int blackboardCount = 64 - whiteboardCount;
            if(fixCount > whiteboardCount || fixCount > blackboardCount) {
                fixCount = min(whiteboardCount, blackboardCount);
            }
        }
    }

    printf("%d", fixCount);

    return 0;
}