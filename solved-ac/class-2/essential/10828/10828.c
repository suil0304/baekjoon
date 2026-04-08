#include <stdio.h>
#include <string.h>

typedef struct Stack {
    int datas[10005];
    int top;
} Stack;

void initStack(Stack* stack);
int push(Stack* stack, int n);
int pop(Stack* stack);
int isEmpty(Stack* stack);
int size(Stack* stack);
int top(Stack* stack);

int main() {
    Stack stack;
    initStack(&stack);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char str[6];
        scanf("%s", str);

        if(strcmp(str, "push") == 0) {
            int num;
            scanf("%d", &num);

            push(&stack, num);
        }
        else if(strcmp(str, "pop") == 0) {
            printf("%d\n", pop(&stack));
        }
        else if(strcmp(str, "size") == 0) {
            printf("%d\n", size(&stack));
        }
        else if(strcmp(str, "empty") == 0) {
            printf("%d\n", isEmpty(&stack));
        }
        else if(strcmp(str, "top") == 0) {
            printf("%d\n", top(&stack));
        }
    }

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
    int poped;
    if(stack->top >= 0) {
        poped = stack->datas[stack->top];
        stack->top--;
    }
    else {
        poped = -1;
    }

    return poped;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int size(Stack* stack) {
    return stack->top + 1;
}

int top(Stack* stack) {
    return !isEmpty(stack) ? stack->datas[stack->top] : -1;
}