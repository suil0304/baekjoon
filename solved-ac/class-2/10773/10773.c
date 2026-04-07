#include <stdio.h>

typedef struct Stack {
    long datas[100000];
    int top;
} Stack;

void initStack(Stack* stack);
long push(Stack* stack, long v);
long pop(Stack* stack);
int isEmpty(Stack* stack);

int main() {
    Stack stack;
    initStack(&stack);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        long num;
        scanf("%ld", &num);

        if(isEmpty(&stack) && num == 0) {
            printf("0");
            return 0;
        }
        else {
            if(num == 0) {
                pop(&stack);
                continue;
            }
            push(&stack, num);
        }
    }

    long long sum = 0;
    while(!isEmpty(&stack)) {
        sum += pop(&stack);
    }

    printf("%lld", sum);

    return 0;
}

void initStack(Stack* stack) {
    stack->top = -1;
}

long push(Stack* stack, long v) {
    stack->top++;
    stack->datas[stack->top] = v;

    return v;
}

long pop(Stack* stack) {
    long poped = stack->datas[stack->top];
    stack->top--;

    return poped;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}