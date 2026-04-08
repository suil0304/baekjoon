#include <stdio.h>
#include <string.h>

typedef struct Queue {
    int datas[10005];
    int start;
    int end;
    int length;
} Queue;

void initQueue(Queue* queue);
int push(Queue* queue, int n);
int pop(Queue* queue);
int size(Queue* queue);
int isEmpty(Queue* queue);
int front(Queue* queue);
int back(Queue* queue);

int main() {
    Queue queue;
    initQueue(&queue);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char str[6];
        scanf("%s", str);

        if(strcmp(str, "push") == 0) {
            int num;
            scanf("%d", &num);

            push(&queue, num);
        }
        else if(strcmp(str, "pop") == 0) {
            printf("%d\n", pop(&queue));
        }
        else if(strcmp(str, "size") == 0) {
            printf("%d\n", size(&queue));
        }
        else if(strcmp(str, "empty") == 0) {
            printf("%d\n", isEmpty(&queue));
        }
        else if(strcmp(str, "front") == 0) {
            printf("%d\n", front(&queue));
        }
        else if(strcmp(str, "back") == 0) {
            printf("%d\n", back(&queue));
        }
    }

    return 0;
}

void initQueue(Queue* queue) {
    queue->start = 0;
    queue->end = -1;
    queue->length = 0;
}

int push(Queue* queue, int n) {
    queue->end++;
    queue->datas[queue->end] = n;
    queue->length++;

    return n;
}

int pop(Queue* queue) {
    int poped;
    if(!isEmpty(queue)) {
        poped = queue->datas[queue->start];
        queue->start++;
        queue->length--;
    }
    else {
        poped = -1;
    }

    return poped;
}

int size(Queue* queue) {
    return queue->length;
}

int isEmpty(Queue* queue) {
    return queue->length == 0;
}

int front(Queue* queue) {
    return !isEmpty(queue) ? queue->datas[queue->start] : -1;
}

int back(Queue* queue) {
    return !isEmpty(queue) ? queue->datas[queue->end] : -1;
}