#include <stdio.h>
#include <limits.h>

int main() {
    int sugar;
    scanf("%d", &sugar);

    int minBag = INT_MAX;
    for(int five = 0; five * 5 <= sugar; five++) {
        for(int three = 0; three * 3 <= sugar; three++) {
            int sum = five * 5 + three * 3;
            int bag = five + three;
            if(sum == sugar && minBag > bag) {
                minBag = bag;
            }
        }
    }

    if(minBag == INT_MAX) {
        minBag = -1;
    }

    printf("%d", minBag);

    return 0;
}