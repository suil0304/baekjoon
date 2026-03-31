#include <stdio.h>

int main() {
    int fullPieces[] = {1, 1, 2, 2, 2, 8};
    int pieces[6];

    for(int i = 0; i < 6; i++) {
        int piece;
        scanf("%d", &piece);

        pieces[i] = fullPieces[i] - piece;
    }

    for(int i = 0; i < 6; i++) {
        printf("%d ", pieces[i]);
    }

    return 0;
}