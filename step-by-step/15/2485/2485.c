#include <stdio.h>
#include <stdlib.h>

int euclideanAlgorithm(int base, int divde);

int main() {
    int t;
    scanf("%d", &t);

    int* differArray;
    differArray = (int*) malloc(sizeof(int) * (t - 1));

    int prev;
    scanf("%d", &prev);
    for(int i = 1; i < t; i++) {
        int num;
        scanf("%d", &num);

        differArray[i - 1] = num - prev;

        prev = num;
    }

    int curGCD = euclideanAlgorithm(differArray[0], differArray[1]);
    for(int i = 2; i < t - 1; i++) {
        curGCD = euclideanAlgorithm(curGCD, differArray[i]);
    }

    int sum = 0;
    for(int i = 0; i < t - 1; i++) {
        sum += differArray[i] / curGCD - 1;
    }

    printf("%d", sum);

    free(differArray);

    return 0;
}

int euclideanAlgorithm(int base, int divde) {
    if(divde == 0) {
        return base;
    }
    return euclideanAlgorithm(divde, base % divde);
}