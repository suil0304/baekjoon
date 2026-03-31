    #include <stdio.h>

    int main() {
        int num;
        scanf("%d", &num);

        int floor = 1;
        int range = 1;
        int addNum = 6;
        while(num > range) {
            range += addNum;
            addNum += 6;
            floor++;
        }

        printf("%d", floor);

        return 0;
    }