#include <stdio.h>

// 주석이 필요한 단계라 느껴 다는 주석의 그 다섯 번째 - O(n³)
/*
    문제의 의사코드:
    ```
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n
            for j <- 1 to n
                for k <- 1 to n
                    sum <- sum + A[i] × A[j] × A[k]; # 코드1
        return sum;
    }
    ```

    O(n³) - 3차 시간(Cubic Time)
    데이터의 크기(n)에 따라 컴퓨터가 해야 할 일의 양이 n³의 꼴로 늘어나는 것.
    선형 시간의 세제곱꼴로 느리다.
    웬만하면 피해야 할 것이라 생각하면 편하다.

    가장 대표적인 것으로 꼽을 수 있는 것:
    - 삼중 for문.
*/

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", n * n * n); // O(n³) - 수행시간이 데이터의 크기의 세제곱꼴을 따름
    printf("%d\n", 3); // 최고 차항 차수 - 미지수 n^3 -> 3

    return 0;
}