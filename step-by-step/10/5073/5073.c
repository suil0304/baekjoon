#include <stdio.h>
#include <math.h>

#define max(a, b) (\
    ((a) > (b)) ? (a) : (b)\
)
#define min(a, b) (\
    ((a) < (b)) ? (a) : (b)\
)

int main() {
    while(1) {
        int lines[3] = {0, };
        scanf("%d %d %d", &lines[0], &lines[1], &lines[2]);

        if(!lines[0] && !lines[1] && !lines[2]) {
            break;
        }

        int maxLine = max(max(lines[0], lines[1]), lines[2]);

        int sum = 0;
        for(int i = 0; i < 3; i++) {
            sum += lines[i];
        }
        
        if(maxLine >= (sum - maxLine)) {
            printf("Invalid\n");
        }
        else if(lines[0] == lines[1] && lines[1] == lines[2]) {
            printf("Equilateral\n");
        }
        else if(lines[0] == lines[1]) {
            printf("Isosceles\n");
        }
        else if(lines[1] == lines[2]) {
            printf("Isosceles\n");
        }
        else if(lines[2] == lines[0]) {
            printf("Isosceles\n");
        }
        else {
            printf("Scalene\n");
        }
    }

    return 0;
}