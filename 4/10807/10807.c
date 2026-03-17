#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);

    int arr[100];
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int v;
    scanf("%d", &v);

    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == v) {
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}