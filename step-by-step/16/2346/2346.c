#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Balloon {
    int originalNum;
    int paperNum;
} Balloon;

typedef struct Deque Deque; // Double-Ended Queue

struct Deque {
    // field
    Balloon* datas;
    int front;
    int rear;
    int length;
    int arrayMaxSize;
    // OOP like
    Balloon (*push)(Deque*, Balloon);
    Balloon (*unshift)(Deque*, Balloon);
    Balloon (*pop)(Deque*);
    Balloon (*shift)(Deque*);
    int (*getLength)(Deque*);
    int (*isEmpty)(Deque*);
};



void initDeque(Deque* deque, int n);
void destroyDeque(Deque* deque);
Balloon _pushDeque(Deque* deque, Balloon balloon);
Balloon _unshiftDeque(Deque* deque, Balloon balloon);
Balloon _popDeque(Deque* deque);
Balloon _shiftDeque(Deque* deque);
int _getLengthDeque(Deque* deque);
int _isEmptyDeque(Deque* deque);

int main() {
    int balloonNum;
    scanf("%d", &balloonNum);

    Deque deque;
    initDeque(&deque, balloonNum);

    for(int i = 1; i <= balloonNum; i++) {
        Balloon balloon;
        balloon.originalNum = i;
        scanf("%d", &balloon.paperNum);

        deque.push(&deque, balloon);
    }

    while(!deque.isEmpty(&deque)) {
        Balloon shifted = deque.shift(&deque);
        printf("%d ", shifted.originalNum);

        if(shifted.paperNum > 0) {
            for(int i = 0; i < shifted.paperNum - 1; i++) {
                deque.push(&deque, deque.shift(&deque));
            }
        }
        else {
            for(int i = 0; i < abs(shifted.paperNum); i++) {
                deque.unshift(&deque, deque.pop(&deque));
            }
        }
    }

    destroyDeque(&deque);

    return 0;
}

void initDeque(Deque* deque, int n) {
    deque->datas = (Balloon*) malloc(sizeof(Balloon) * (n + 1));
    deque->arrayMaxSize = n + 1;
    deque->front = 1;
    deque->rear = 0;
    deque->length = 0;

    deque->push = _pushDeque;
    deque->unshift = _unshiftDeque;
    deque->pop = _popDeque;
    deque->shift = _shiftDeque;
    deque->getLength = _getLengthDeque;
    deque->isEmpty = _isEmptyDeque;
}

void destroyDeque(Deque* deque) {
    free(deque->datas);
    deque->arrayMaxSize = -1;
    deque->front = -1;
    deque->rear = -1;
    deque->length = 0;

    deque->push = NULL;
    deque->unshift = NULL;
    deque->pop = NULL;
    deque->shift = NULL;
    deque->getLength = NULL;
    deque->isEmpty = NULL;
}

Balloon _pushDeque(Deque* deque, Balloon balloon) {
    deque->rear = (deque->rear + 1) % deque->arrayMaxSize;
    deque->datas[deque->rear] = balloon;
    deque->length++;

    return balloon;
}

Balloon _unshiftDeque(Deque* deque, Balloon balloon) {
    deque->front = (deque->front - 1 + deque->arrayMaxSize) % deque->arrayMaxSize;
    deque->datas[deque->front] = balloon;
    deque->length++;

    return balloon;
}

Balloon _popDeque(Deque* deque) {
    Balloon poped = deque->datas[deque->rear];
    deque->rear = (deque->rear - 1 + deque->arrayMaxSize) % deque->arrayMaxSize;
    deque->length--;

    return poped;
}

Balloon _shiftDeque(Deque* deque) {
    Balloon shifted = deque->datas[deque->front];
    deque->front = (deque->front + 1) % deque->arrayMaxSize;
    deque->length--;

    return shifted;
}

int _getLengthDeque(Deque* deque) {
    return deque->length;
}

int _isEmptyDeque(Deque* deque) {
    return deque->length == 0;
}