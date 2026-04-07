#include <stdio.h>
#include <stdlib.h>

// 생각해보니 전혀 모르는 상태로 Quick Sort를 사용하고 있던 것 같음
// 그래서 이번 문제는 직접 구현한 다음 사용하기로 했습니다.
// 그런 김에 이분 탐색도 배워왔음(stdlib.h의 bsearch)
// 아니 근데 시간 초과가 나버리네???
// 어쩔 수 없이 stdlib.h의 함수들을 사용하게 되었습니다.

int compare(const void* a, const void* b);
// void quickSort(int* arr, int low, int high);
// int binarySearch(int* arr, int low, int high, int key);

int main() {
    int n;
    scanf("%d", &n);

    int* nums;
    nums = (int*) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        nums[i] = num;
    }

    qsort(nums, n, sizeof(int), compare);

    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++) {
        int query;
        scanf("%d", &query);

        printf("%d\n", bsearch(&query, nums, n, sizeof(int), compare) != NULL);
    }

    free(nums);

    return 0;
}

int compare(const void* a, const void* b) {
    if(*(int*) a > *(int*) b) {
        return 1;
    }
    else if(*(int*) a < *(int*) b) {
        return -1;
    }
    return 0;
}

// 오직 quickSort를 위해 쓰이는 부가 함수(콜백이 아닌)이기에 구현을 생략했습니다.
// 여기가 접근 지정자 있는 언어였다면 private 바로 박았음 ㅇㅇ
// 그래서 _partition이라 이름 지었어요
// int _partition(int* arr, int low, int high) {
//     int pivot = arr[high]; // 맨 끝을 Pivot으로 잡다(한 마디로 기준점)
//     int minLine = low - 1; // 작은 값이 들어갈 한계선

//     for(int i = low; i < high; i++) {
//         if(arr[i] < pivot) {
//             minLine++; // Pivot보다 작은 것이 1개 더 있음 -> 경계선 밀기

//             // 가장 간단할 자리 바꾸기 로직
//             int temp = arr[minLine];
//             arr[minLine] = arr[i];
//             arr[i] = temp;
//         }
//     }

//     // 제자리 찾기
//     int temp = arr[minLine + 1];
//     arr[minLine + 1] = arr[high];
//     arr[high] = temp;

//     return minLine + 1;
// }

// void quickSort(int* arr, int low, int high) {
//     if(low < high) {
//         int pivot = _partition(arr, low, high);

//         quickSort(arr, low, pivot - 1);
//         quickSort(arr, pivot + 1, high);
//     }
// }

// int binarySearch(int* arr, int low, int high, int key) {
//     if(low > high) {
//         return 0;
//     }

//     int mid = low + (high - low) / 2;

//     if(arr[mid] == key) {
//         return 1;
//     }
//     else if(arr[mid] > key) {
//         return binarySearch(arr, low, mid - 1, key);
//     }
//     else {
//         return binarySearch(arr, mid + 1, high, key);
//     }
// }