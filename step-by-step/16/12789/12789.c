#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack {
    int* datas;
    int top;
    int (*push)(Stack*, int);
    int (*pop)(Stack*);
    int (*getLength)(Stack*);
    int (*isEmpty)(Stack*);
    int (*getTop)(Stack*);
};

void initStack(Stack* stack, int n);
void destroyStack(Stack* stack);
int _pushStack(Stack* stack, int n);
int _popStack(Stack* stack);
int _getLengthStack(Stack* stack);
int _isEmptyStack(Stack* stack);
int _getTopStack(Stack* stack);

int main() {
    int n;
    scanf("%d", &n);

    Stack stack;
    initStack(&stack, n);

    int* people;
    people = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        people[i] = num;
    }

    int curPeopleNum = 1;
    for(int i = 0; i < n; i++) {
        if(stack.getTop(&stack) == curPeopleNum) {
            while(stack.getTop(&stack) == curPeopleNum) {
                stack.pop(&stack);
                curPeopleNum++;
            }
        }

        if(people[i] > curPeopleNum) {
            if(stack.isEmpty(&stack)) {
                stack.push(&stack, people[i]);
            }
            else if(people[i] > stack.getTop(&stack)) {
                destroyStack(&stack);
                printf("Sad");

                return 0;
            }
            else {
                stack.push(&stack, people[i]);
            }

        }

        if(people[i] == curPeopleNum) {
            curPeopleNum++;
        }
    }

    while(stack.getTop(&stack) == curPeopleNum) {
        stack.pop(&stack);
        curPeopleNum++;
    }

    printf("%s", curPeopleNum == n + 1 ? "Nice" : "Sad");

    destroyStack(&stack);

    return 0;
}

void initStack(Stack* stack, int n) {
    stack->datas = (int*) malloc(sizeof(int) * n);
    stack->top = -1;

    stack->push = _pushStack;
    stack->pop = _popStack;
    stack->getLength = _getLengthStack;
    stack->isEmpty = _isEmptyStack;
    stack->getTop = _getTopStack;
}

void destroyStack(Stack* stack) {
    free(stack->datas);
    stack->top = -1;

    stack->push = NULL;
    stack->pop = NULL;
    stack->getLength = NULL;
    stack->isEmpty = NULL;
    stack->getTop = NULL;
}

int _pushStack(Stack* stack, int n) {
    stack->top++;
    stack->datas[stack->top] = n;

    return n;
}

int _popStack(Stack* stack) {
    int poped = -1;
    if(stack->top != -1) {
        poped = stack->datas[stack->top];
        stack->top--;
    }

    return poped;
}

int _getLengthStack(Stack* stack) {
    return stack->top + 1;
}

int _isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

int _getTopStack(Stack* stack) {
    int top = -1;
    if(stack->top != -1) {
        top = stack->datas[stack->top];
    }

    return top;
}