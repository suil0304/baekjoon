#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* datas;
    int start;
    int end;
    int size;
    int length;
} Queue;

void initQueue(Queue* queue, int n);
int push(Queue* queue, int n);
int shift(Queue* queue);
int isEmpty(Queue* queue);
void destroyQueue(Queue* queue);

int main() {
    int n;
    scanf("%d", &n);

    Queue queue;
    initQueue(&queue, n);

    for(int i = 1; i <= n; i++) {
        push(&queue, i);
    }

    int deleteNum;
    scanf("%d", &deleteNum);

    printf("<");

    for(int i = 1; !isEmpty(&queue); i++) {
        int poped = shift(&queue);
        if(i % deleteNum != 0) {
            push(&queue, poped);
        }
        else {
            printf("%d", poped);
            if(!isEmpty(&queue)) {
                printf(", ");
            }
        }
    }

    printf(">");

    destroyQueue(&queue);

    return 0;
}

void initQueue(Queue* queue, int n) {
    queue->datas = (int*) malloc(sizeof(int) * (n + 1));
    queue->size = n + 1;
    queue->start = 0;
    queue->end = -1;
    queue->length = 0;
}

int push(Queue* queue, int n) {
    queue->end = (queue->end + 1) % queue->size;
    queue->datas[queue->end] = n;
    queue->length++;

    return n;
}

int shift(Queue* queue) {
    int shifted = queue->datas[queue->start];
    queue->start = (queue->start + 1) % queue->size;
    queue->length--;

    return shifted;
}

int isEmpty(Queue* queue) {
    return queue->length == 0;
}

void destroyQueue(Queue* queue) {
    free(queue->datas);
    queue->size = 0;
    queue->start = -1;
    queue->end = -1;
    queue->length = -1;
}