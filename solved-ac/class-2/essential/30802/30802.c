#include <stdio.h>
#include <math.h>

int main() {
    int people;
    scanf("%d", &people);

    int tshirtSizes[6] = {0, };
    for(int i = 0; i < 6; i++) {
        scanf("%d", &tshirtSizes[i]);
    }

    double tshirt;
    int pen;
    scanf("%lf %d", &tshirt, &pen);

    int needTshirt = 0;
    for(int i = 0; i < 6; i++) {
        needTshirt += (int) ceil(tshirtSizes[i] / tshirt);
    }

    printf("%d\n", needTshirt);
    printf("%d %d\n", people / pen, people % pen);

    return 0;
}