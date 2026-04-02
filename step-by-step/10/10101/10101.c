#include <stdio.h>

int main() {
    int angles[3] = {0, };
    int angleChecks[180] = {0, };
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &angles[i]);

        sum += angles[i];
        angleChecks[angles[i] - 1]++;
    }

    if(sum != 180) {
        printf("Error");
        return 0;
    }

    int correctStat = 0;
    for(int i = 0; i < 3; i++) {
        int angle = angles[i];
        if(angleChecks[angle - 1] > 1) {
            correctStat = angleChecks[angle - 1];
            break;
        }
    }
    
    if(correctStat == 3) {
        printf("Equilateral");
    }
    else if(correctStat == 2) {
        printf("Isosceles");
    }
    else {
        printf("Scalene");
    }

    return 0;
}