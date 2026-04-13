#include <stdio.h>

typedef struct Stack Stack;

struct Stack {
    int datas[1000000];
    int top;
    int (*push)(Stack*, int);
    int (*pop)(Stack*);
    int (*getLength)(Stack*);
    int (*isEmpty)(Stack*);
    int (*getTop)(Stack*);
};

Stack stack;

void initStack(Stack* stack);
void destroyStack(Stack* stack);
int _pushStack(Stack* stack, int n);
int _popStack(Stack* stack);
int _getLengthStack(Stack* stack);
int _isEmptyStack(Stack* stack);
int _getTopStack(Stack* stack);

int main() {
    initStack(&stack);

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int command;
        scanf("%d", &command);

        switch(command) {
            case 1:
                int num;
                scanf("%d", &num);

                stack.push(&stack, num);
                break;
            case 2:
                printf("%d\n", stack.pop(&stack));
                break;
            case 3:
                printf("%d\n", stack.getLength(&stack));
                break;
            case 4:
                printf("%d\n", stack.isEmpty(&stack));
                break;
            case 5:
                printf("%d\n", stack.getTop(&stack));
                break;
        }
    }

    destroyStack(&stack);

    return 0;
}

void initStack(Stack* stack) {
    stack->top = -1;

    stack->push = _pushStack;
    stack->pop = _popStack;
    stack->getLength = _getLengthStack;
    stack->isEmpty = _isEmptyStack;
    stack->getTop = _getTopStack;
}

void destroyStack(Stack* stack) {
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