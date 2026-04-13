#include <stdio.h>
#include <string.h>

typedef struct Stack {
    char datas[105];
    int top;
} Stack;

void initStack(Stack* stack);
char push(Stack* stack, char c);
char pop(Stack* stack);
int isEmpty(Stack* stack);

int main() {
    Stack stack;
    initStack(&stack);

    char str[105] = {0, };
    while(1) {
        fgets(str, sizeof(str), stdin);

        if(strcmp(str, ".\n") == 0) {
            break;
        }

        int length = strlen(str);
        for(int i = 0; i < length; i++) {
            char c = str[i];

            if(c == '(' || c == '[') {
                push(&stack, c);
                continue;
            }

            if(c != ')' && c != ']') {
                continue;
            }

            if(isEmpty(&stack)) {
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
            printf("yes\n");
        }
        else {
            printf("no\n");
        }

        initStack(&stack);
    }
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