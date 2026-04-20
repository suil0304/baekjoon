#include <stdio.h>
#include <string.h>

typedef struct Queue Queue;

struct Queue {
    // field
    int datas[2000001];
    int front;
    int rear;
    int length;
    // OOP like
    int (*push)(Queue*, int);
    int (*shift)(Queue*);
    int (*getSize)(Queue*);
    int (*isEmpty)(Queue*);
    int (*getFront)(Queue*);
    int (*getRear)(Queue*);
};

Queue queue;

void initQueue(Queue* queue);
void destroyQueue(Queue* queue);
int _pushQueue(Queue* queue, int n);
int _shiftQueue(Queue* queue);
int _getSizeQueue(Queue* queue);
int _isEmptyQueue(Queue* queue);
int _getFrontQueue(Queue* queue);
int _getRearQueue(Queue* queue);

int main() {
    initQueue(&queue);

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        char command[6];
        scanf("%s", command);

        if(strcmp(command, "push") == 0) {
            int num;
            scanf("%d", &num);

            queue.push(&queue, num);
        }
        else if(strcmp(command, "pop") == 0) {
            printf("%d\n", queue.shift(&queue));
        }
        else if(strcmp(command, "size") == 0) {
            printf("%d\n", queue.getSize(&queue));
        }
        else if(strcmp(command, "empty") == 0) {
            printf("%d\n", queue.isEmpty(&queue));
        }
        else if(strcmp(command, "front") == 0) {
            printf("%d\n", queue.getFront(&queue));
        }
        else if(strcmp(command, "back") == 0) {
            printf("%d\n", queue.getRear(&queue));
        }
    }

    destroyQueue(&queue);

    return 0;
}

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->length = 0;

    queue->push = _pushQueue;
    queue->shift = _shiftQueue;
    queue->getSize = _getSizeQueue;
    queue->isEmpty = _isEmptyQueue;
    queue->getFront = _getFrontQueue;
    queue->getRear = _getRearQueue;
}

void destroyQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->length = 0;

    queue->push = NULL;
    queue->shift = NULL;
    queue->getSize = NULL;
    queue->isEmpty = NULL;
    queue->getFront = NULL;
    queue->getRear = NULL;
}

int _pushQueue(Queue* queue, int n) {
    queue->rear++;
    queue->datas[queue->rear] = n;
    queue->length++;

    return n;
}

int _shiftQueue(Queue* queue) {
    int unshifted = -1;
    if(!queue->isEmpty(queue)) {
        unshifted = queue->datas[queue->front];
        queue->front++;
        queue->length--;
    }

    return unshifted;
}

int _getSizeQueue(Queue* queue) {
    return queue->length;
}

int _isEmptyQueue(Queue* queue) {
    return queue->length == 0;
}

int _getFrontQueue(Queue* queue) {
    return !queue->isEmpty(queue) ? queue->datas[queue->front] : -1;
}

int _getRearQueue(Queue* queue) {
    return !queue->isEmpty(queue) ? queue->datas[queue->rear] : -1;
}