#include <stdio.h>

// 주석이 필요한 단계라 느껴 다는 주석의 그 두 번째 - O(n)
/*
    문제의 의사코드:
    ```
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n
            sum <- sum + A[i]; # 코드1
        return sum;
    }
    ```

    O(n) - 선형 시간(Linear Time)
    데이터의 크기(n)에 따라 컴퓨터가 해야 할 일의 양이 n의 꼴로 늘어나는 것.
    상수 시간에 비해 느리다.

    가장 대표적인 것으로 꼽을 수 있는 것:
    - for문.
*/

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n); // O(n) - 수행시간이 데이터의 크기를 따름
    printf("%d\n", 1); // 최고 차항 차수 - 미지수 n^1 -> 1

    return 0;
}