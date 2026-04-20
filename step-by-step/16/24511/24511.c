#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;

struct Queue {
    int* datas;
    int front;
    int rear;
    int length;
    int arrayMaxSize;
    int (*push)(Queue*, int);
    int (*shift)(Queue*);
    int (*isEmpty)(Queue*);
};

void initQueue(Queue* queue, int n);
void destroyQueue(Queue* queue);
int _pushQueue(Queue* queue, int n);
int _shiftQueue(Queue* queue);
int _isEmptyQueue(Queue* queue);

int main() {
    int n;
    scanf("%d", &n);

    Queue queue;
    initQueue(&queue, 200000);

    int* isQueue;
    isQueue = (int*) malloc(sizeof(int) * n);

    int boolCount = 0;
    for(int i = 0; i < n; i++) {
        int boolean;
        scanf("%d", &boolean);

        isQueue[i] = boolean == 0;

        if(boolean == 0) {
            boolCount++;
        }
    }

    int* queueNums;
    queueNums = (int*) malloc(sizeof(int) * boolCount);

    int queueNumsIndex = 0;
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if(isQueue[i]) {
            queueNums[queueNumsIndex] = num;
            queueNumsIndex++;
        }
    }

    for(int i = queueNumsIndex - 1; i >= 0; i--) {
        queue.push(&queue, queueNums[i]);
    }

    int newNum;
    scanf("%d", &newNum);

    for(int i = 0; i < newNum; i++) {
        int num;
        scanf("%d", &num);

        queue.push(&queue, num);
    }

    for(int i = 0; i < newNum; i++) {
        printf("%d ", queue.shift(&queue));
    }

    free(isQueue);
    free(queueNums);

    destroyQueue(&queue);

    return 0;
}

void initQueue(Queue* queue, int n) {
    queue->datas = (int*) malloc(sizeof(int) * (n + 1));
    queue->arrayMaxSize = n + 1;
    queue->front = 1;
    queue->rear = 0;
    queue->length = 0;

    queue->push = _pushQueue;
    queue->shift = _shiftQueue;
    queue->isEmpty = _isEmptyQueue;
}

void destroyQueue(Queue* queue) {
    free(queue->datas);
    queue->arrayMaxSize = -1;
    queue->front = -1;
    queue->rear = -1;
    queue->length = 0;

    queue->push = NULL;
    queue->shift = NULL;
    queue->isEmpty = NULL;
}

int _pushQueue(Queue* queue, int n) {
    queue->rear = (queue->rear + 1) % queue->arrayMaxSize;
    queue->datas[queue->rear] = n;
    queue->length++;

    return n;
}

int _shiftQueue(Queue* queue) {
    int shifted = queue->datas[queue->front];
    queue->front = (queue->front + 1) % queue->arrayMaxSize;
    queue->length--;

    return shifted;
}

int _isEmptyQueue(Queue* queue) {
    return queue->length == 0;
}