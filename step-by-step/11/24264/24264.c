#include <stdio.h>

// 주석이 필요한 단계라 느껴 다는 주석의 그 세 번째 - O(n²)
/*
    문제의 의사코드:
    ```
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n
            for j <- 1 to n
                sum <- sum + A[i] × A[j]; # 코드1
        return sum;
    }
    ```

    O(n²) - 2차 시간(Quadratic Time)
    데이터의 크기(n)에 따라 컴퓨터가 해야 할 일의 양이 n²의 꼴로 늘어나는 것.
    선형 시간의 제곱꼴로 느리다.

    가장 대표적인 것으로 꼽을 수 있는 것:
    - 이중 for문.
*/

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", n * n); // O(n²) - 수행시간이 데이터의 크기의 제곱꼴을 따름
    printf("%ld\n", 2); // 최고 차항 차수 - 미지수 n^2 -> 2

    return 0;
}