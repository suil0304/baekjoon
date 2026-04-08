#include <stdio.h>
#include <stdlib.h>

typedef struct Document {
    int priority;
    int originalIndex;
} Document;

typedef struct Queue {
    Document* datas;
    int start;
    int end;
    int size;
    int length;
} Queue;

// queue
void initQueue(Queue* queue, int n);
Document push(Queue* queue, Document document);
Document shift(Queue* queue);
int isEmpty(Queue* queue);
void destroyQueue(Queue* queue);
// qsort compare function
int compare(const void* a, const void* b);

int main() {
    Queue queue;

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int docuNum, queryIndex;
        scanf("%d %d", &docuNum, &queryIndex);

        initQueue(&queue, docuNum);

        int* priorities;
        priorities = (int*) malloc(sizeof(int) * docuNum);

        for(int i = 0; i < docuNum; i++) {
            int priority;
            scanf("%d", &priority);

            Document document;
            document.priority = priority;
            document.originalIndex = i;

            push(&queue, document);
            priorities[i] = priority;
        }

        qsort(priorities, docuNum, sizeof(int), compare);

        int count = 0;
        while(!isEmpty(&queue)) {
            Document shifted = shift(&queue);
            if(shifted.priority == priorities[count]) {
                count++;
                if(shifted.originalIndex == queryIndex) {
                    break;
                }
            }
            else {
                push(&queue, shifted);
            }
        }

        printf("%d\n", count);

        destroyQueue(&queue);
        free(priorities);
    }

    return 0;
}

void initQueue(Queue* queue, int n) {
    queue->datas = (Document*) malloc(sizeof(Document) * (n + 1));
    queue->size = n + 1;
    queue->start = 0;
    queue->end = -1;
    queue->length = 0;
}

Document push(Queue* queue, Document n) {
    queue->end = (queue->end + 1) % queue->size;
    queue->datas[queue->end] = n;
    queue->length++;

    return n;
}

Document shift(Queue* queue) {
    Document shifted = queue->datas[queue->start];
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

int compare(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}