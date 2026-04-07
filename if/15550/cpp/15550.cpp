#include <iostream>
#include <limits>

// 도움 받음: 인터넷(https://ddmanager.pe.kr/41)

int main() {
    // float형은 정밀도가 떨어져서 99999999와 99999998이 같다 판단됨
    int a = 99999998;
    float b = 99999998;
    int c = 99999999;

    std::cout << (a == b && b == c && c != a) << std::endl;

    return 0;
}