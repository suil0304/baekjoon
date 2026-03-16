#include <stdio.h>

int main() {
    int money, t;
    scanf("%d", &money);
    scanf("%d", &t);

    int sum = 0;
    for(int _ = 0; _ < t; _++) {
        int itemMoney, itemCount;
        scanf("%d %d", &itemMoney, &itemCount);
        sum += itemMoney * itemCount;
    }

    printf(money == sum ? "Yes" : "No");

    return 0;
}