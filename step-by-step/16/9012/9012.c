#include <stdio.h>
#include <string.h>

typedef struct Stack {
    char datas[55];
    int top;
} Stack;

void initStack(Stack* stack);
char push(Stack* stack, char c);
char pop(Stack* stack);
int isEmpty(Stack* stack);

int main() {
    int n;
    scanf("%d", &n);

    Stack stack;
    initStack(&stack);

    char str[55];
    for(int _ = 0; _ < n; _++) {
        scanf("%s", str);

        int length;
        length = strlen(str);

        for(int i = 0; i < length; i++) {
            char c = str[i];
            if(c == '(' || c == '[') {
                push(&stack, c);
                continue;
            }

            if(isEmpty(&stack) && (c == ')' || c == ']')) {
                push(&stack, c);
                break;
            }

            char topChar = stack.datas[stack.top];
            if((topChar == '(' && c == ')') || (topChar == '[' && c == ']')) {
                pop(&stack);
            }
            else if((topChar == '(' && c == ']') || (topChar == '[' && c == ')')) {
                break;
            }
        }

        if(isEmpty(&stack)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }

        initStack(&stack);
    }

    return 0;
}

void initStack(Stack* stack) {
    stack->top = -1;
}

char push(Stack* stack, char c) {
    stack->top++;
    stack->datas[stack->top] = c;

    return c;
}

char pop(Stack* stack) {
    char poped = stack->datas[stack->top];
    stack->top--;

    return poped;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}