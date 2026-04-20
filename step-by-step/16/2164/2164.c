#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* datas; // 동적 할당
    int start;
    int end;
    int length;
    int size;
} Queue;

void initQueue(Queue* queue, unsigned int num);
int push(Queue* queue, int x); // 들어간 값을 그대로 반환
int shift(Queue* queue); // 뺀 값을 그대로 반환
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

    while(queue.length != 1) {
        shift(&queue);
        push(&queue, shift(&queue));
    }

    printf("%d", shift(&queue));

    destroyQueue(&queue);

    return 0;
}

void initQueue(Queue* queue, unsigned int num) {
    queue->datas = (int*) malloc(sizeof(int) * (num + 1));
    queue->start = 0;
    queue->end = -1;
    queue->length = 0;
    queue->size = num;
}

int push(Queue* queue, int x) {
    queue->end = (queue->end + 1) % queue->size;
    queue->datas[queue->end] = x;
    queue->length++;

    return x;
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
    queue->start = -1;
    queue->end = -1;
    queue->length = -1;
    queue->size = -1;
}