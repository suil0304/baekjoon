#include <stdio.h>

int main() {
    int nums[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int notDupeCount = 0;
    for(int i = 0; i < 10; i++) {
        int num;
        scanf("%d", &num);
        num %= 42;

        for(int j = 0; j <= notDupeCount; j++) {
            if(nums[j] == num) {
                break;
            }

            if(j == notDupeCount) {
                nums[j] = num;
                notDupeCount++;
                break;
            }
        }
    }

    printf("%d\n", notDupeCount);

    return 0;
}