#include <stdio.h>

// 주석이 필요한 단계라 느껴 다는 주석의 그 여섯 번째 - O(n³)의 변형
/*
    문제의 의사코드:
    ```
    MenOfPassion(A[], n) {
        sum <- 0;
        for i <- 1 to n - 2
            for j <- i + 1 to n - 1
                for k <- j + 1 to n
                    sum <- sum + A[i] × A[j] × A[k]; # 코드1
        return sum;
    }
    ```

    O(n³)의 변형
    실제 연산 횟수가 얼마나 적어지든 데이터의 양이 10배가 늘어났을 때
    컴퓨터가 할 일의 양이 1000배 = 10³배의 꼴로 늘어난다면 O(n³)이다.
*/

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", (n * (n - 1) * (n - 2)) / 6); // n C r = n! / ((n - r)! * r!)
    printf("%d\n", 3); // 최고 차항 차수 - 미지수 n^3 -> 3

    return 0;
}