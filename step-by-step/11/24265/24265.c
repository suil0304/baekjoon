#include <stdio.h>

// 주석이 필요한 단계라 느껴 다는 주석의 그 네 번째 - O(n²)의 변형
/*
    문제의 의사코드:
    ```
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n - 1
            for j <- i + 1 to n
                sum <- sum + A[i] × A[j]; # 코드1
        return sum;
    }
    ```

    O(n²)의 변형
    실제 연산 횟수가 얼마나 적어지든 데이터의 양이 10배가 늘어났을 때
    컴퓨터가 할 일의 양이 100배 = 10²배의 꼴로 늘어난다면 O(n²)이다.
*/

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", ((n - 1) * n) / 2); // O(n²) - 1부터 n-1의 합에 n을 곱하여 계산, 평균 연산 횟수가 절반이기에 /2
    printf("%ld\n", 2); // 최고 차항 차수 - 미지수 n^2 -> 2

    return 0;
}