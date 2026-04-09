#include <stdio.h>
#include <stdlib.h>

// 도움 받음 - AI + 인터넷 (C11 (Clang) 이슈)

int compareNum(const void* a, const void* b);

int main() {
    int craneNum;
    scanf("%d", &craneNum);

    int* cranes;
    cranes = (int*) calloc(craneNum, sizeof(int));
    for(int i = 0; i < craneNum; i++) {
        scanf("%d", &cranes[i]);
    }

    int boxNum;
    scanf("%d", &boxNum);

    int* boxes;
    boxes = (int*) calloc(boxNum, sizeof(int));
    for(int i = 0; i < boxNum; i++) {
        scanf("%d", &boxes[i]);
    }
    
    qsort(cranes, craneNum, sizeof(int), compareNum);
    qsort(boxes, boxNum, sizeof(int), compareNum);

    if(boxes[0] > cranes[0]) {
        printf("%d\n", -1);

        free(cranes);
        free(boxes);

        return 0;
    }

    int time;
    int boxMovedCount = 0;
    for(time = 0; boxMovedCount != boxNum; time++) {
        int craneIndex = 0;

        for(int j = 0; j < boxNum; j++) {
            if(craneIndex == craneNum) {
                break;
            }

            if(!boxes[j]) {
                continue;
            }

            if(boxes[j] > cranes[craneIndex]) {
                continue;
            }
            
            boxes[j] = 0;
            craneIndex++;
            boxMovedCount++;
        }
    }

    printf("%d", time);

    free(cranes);
    free(boxes);

    return 0;
}

int compareNum(const void* a, const void* b) { // descending
    return *(int*) b - *(int*) a;
}