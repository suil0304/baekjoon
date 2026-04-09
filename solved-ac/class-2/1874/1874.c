#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int datas[100000];
    int top;
} Stack;

void initStack(Stack* stack);
int push(Stack* stack, int n);
int pop(Stack* stack);
int isEmpty(Stack* stack);
int getTop(Stack* stack);

int main() {
    Stack stack;
    initStack(&stack);

    int n;
    scanf("%d", &n);

    int* nums;
    nums = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        nums[i] = num;
    }

    int curNumIndex = 0;
    char commands[200005] = {0, };
    int commandIndex = 0;
    int lastPush = 0;

    while(curNumIndex != n) {
        int curNum = nums[curNumIndex];
        if(getTop(&stack) > curNum) {
            printf("NO");
            free(nums);

            return 0;
        }
        else if(getTop(&stack) < curNum) {
            int i = lastPush + 1;
            for(i; getTop(&stack) != curNum; i++) {
                push(&stack, i);
                commands[commandIndex] = '+';
                commandIndex++;
                lastPush = i;
            }
        }

        pop(&stack);
        commands[commandIndex] = '-';
        commandIndex++;

        curNumIndex++;
    }

    for(int i = 0; i < commandIndex; i++) {
        printf("%c\n", commands[i]);
    }

    free(nums);

    return 0;
}

void initStack(Stack* stack) {
    stack->top = -1;
}

int push(Stack* stack, int n) {
    stack->top++;
    stack->datas[stack->top] = n;

    return n;
}

int pop(Stack* stack) {
    int poped = stack->datas[stack->top];
    stack->top--;

    return poped;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int getTop(Stack* stack) {
    return !isEmpty(stack) ? stack->datas[stack->top] : -1;
}