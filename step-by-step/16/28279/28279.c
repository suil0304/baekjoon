#include <stdio.h>

#define DEQUE_DATA_MAX 1000001

typedef struct Deque Deque; // Double-Ended Queue

struct Deque {
    // field
    int datas[1000001];
    int front;
    int rear;
    int length;
    // OOP like
    int (*push)(Deque*, int);
    int (*unshift)(Deque*, int);
    int (*pop)(Deque*);
    int (*shift)(Deque*);
    int (*getLength)(Deque*);
    int (*isEmpty)(Deque*);
    int (*getFront)(Deque*);
    int (*getRear)(Deque*);
};

Deque deque;

void initDeque(Deque* deque);
void destroyDeque(Deque* deque);
int _pushDeque(Deque* deque, int n);
int _unshiftDeque(Deque* deque, int n);
int _popDeque(Deque* deque);
int _shiftDeque(Deque* deque);
int _getLengthDeque(Deque* deque);
int _isEmptyDeque(Deque* deque);
int _getFrontDeque(Deque* deque);
int _getRearDeque(Deque* deque);

int main() {
    initDeque(&deque);

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int command;
        scanf("%d", &command);

        int num;
        switch(command) {
            case 1:
                scanf("%d", &num);

                deque.unshift(&deque, num);
                break;
            case 2:
                scanf("%d", &num);

                deque.push(&deque, num);
                break;
            case 3:
                printf("%d\n", deque.shift(&deque));
                break;
            case 4:
                printf("%d\n", deque.pop(&deque));
                break;
            case 5:
                printf("%d\n", deque.getLength(&deque));
                break;
            case 6:
                printf("%d\n", deque.isEmpty(&deque));
                break;
            case 7:
                printf("%d\n", deque.getFront(&deque));
                break;
            case 8:
                printf("%d\n", deque.getRear(&deque));
                break;
        }
    }

    destroyDeque(&deque);

    return 0;
}

void initDeque(Deque* deque) {
    deque->front = 1;
    deque->rear = 0;
    deque->length = 0;

    deque->push = _pushDeque;
    deque->unshift = _unshiftDeque;
    deque->pop = _popDeque;
    deque->shift = _shiftDeque;
    deque->getLength = _getLengthDeque;
    deque->isEmpty = _isEmptyDeque;
    deque->getFront = _getFrontDeque;
    deque->getRear = _getRearDeque;
}

void destroyDeque(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
    deque->length = 0;

    deque->push = NULL;
    deque->unshift = NULL;
    deque->pop = NULL;
    deque->shift = NULL;
    deque->getLength = NULL;
    deque->isEmpty = NULL;
    deque->getFront = NULL;
    deque->getRear = NULL;
}

int _pushDeque(Deque* deque, int n) {
    deque->rear = (deque->rear + 1) % DEQUE_DATA_MAX;
    deque->datas[deque->rear] = n;
    deque->length++;

    return n;
}

int _unshiftDeque(Deque* deque, int n) {
    deque->front = (deque->front - 1 + DEQUE_DATA_MAX) % DEQUE_DATA_MAX;
    deque->datas[deque->front] = n;
    deque->length++;

    return n;
}

int _popDeque(Deque* deque) {
    int poped = -1;
    if(!deque->isEmpty(deque)) {
        poped = deque->datas[deque->rear];
        deque->rear = (deque->rear - 1 + DEQUE_DATA_MAX) % DEQUE_DATA_MAX;
        deque->length--;
    }

    return poped;
}

int _shiftDeque(Deque* deque) {
    int shifted = -1;
    if(!deque->isEmpty(deque)) {
        shifted = deque->datas[deque->front];
        deque->front = (deque->front + 1) % DEQUE_DATA_MAX;
        deque->length--;
    }

    return shifted;
}

int _getLengthDeque(Deque* deque) {
    return deque->length;
}

int _isEmptyDeque(Deque* deque) {
    return deque->length == 0;
}

int _getFrontDeque(Deque* deque) {
    return !deque->isEmpty(deque) ? deque->datas[deque->front] : -1;
}

int _getRearDeque(Deque* deque) {
    return !deque->isEmpty(deque) ? deque->datas[deque->rear] : -1;
}