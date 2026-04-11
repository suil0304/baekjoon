#include <stdio.h>

int euclideanAlgorithm(int base, int divde);

int main() {
    int aNumerator, aDenominator;
    scanf("%d %d", &aNumerator, &aDenominator);

    int bNumerator, bDenominator;
    scanf("%d %d", &bNumerator, &bDenominator);

    int newANumerator = aNumerator * bDenominator;
    int newBNumerator = bNumerator * aDenominator;

    int newDenominator = aDenominator * bDenominator;

    newANumerator += newBNumerator;

    int irreducibleGCD = euclideanAlgorithm(newANumerator, newDenominator);

    newANumerator /= irreducibleGCD;
    newDenominator /= irreducibleGCD;

    printf("%d %d", newANumerator, newDenominator);

    return 0;
}

int euclideanAlgorithm(int base, int divde) {
    if(divde == 0) {
        return base;
    }
    return euclideanAlgorithm(divde, base % divde);
}