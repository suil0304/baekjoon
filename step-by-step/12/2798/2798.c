#include <stdio.h>
#include <stdlib.h>

int main() {
    int cardNum, maximum;
    scanf("%d %d", &cardNum, &maximum);

    int* cards;
    cards = (int*) calloc(cardNum, sizeof(int));

    for(int i = 0; i < cardNum; i++) {
        scanf("%d", &cards[i]);
    }

    int sum = 0;
    for(int i = 0; i < cardNum; i++) {
        for(int j = 0; j < cardNum; j++) {
            if(i == j) {
                continue;
            }

            for(int k = 0; k < cardNum; k++) {
                if(i == k || j == k) {
                    continue;
                }

                int _sum = cards[i] + cards[j] + cards[k];
                if(sum < _sum && _sum <= maximum) {
                    sum = _sum;
                }
            }
        }
    }

    printf("%d", sum);

    free(cards);

    return 0;
}