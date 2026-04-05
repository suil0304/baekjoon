#include <stdio.h>

// 이거 브루트 포스 아니구나
// 수학 공부의 중요성

int euclideanAlgorithm(int a, int b);

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int maxYacksu;
    maxYacksu = euclideanAlgorithm(num1, num2);
    
    int minBaesu;
    minBaesu = (num1 * num2) / maxYacksu;

    printf("%d\n", maxYacksu);
    printf("%d\n", minBaesu);

    return 0;
}

int euclideanAlgorithm(int base, int divNum) {
    if(divNum == 0) {
        return base;
    }
    return euclideanAlgorithm(divNum, base % divNum);
}