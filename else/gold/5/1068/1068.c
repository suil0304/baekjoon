#include <stdio.h>
#include <stdlib.h>

int** connected;
int n;
int count = 0;

void dfsThingie(int parent);

int main() {
    scanf("%d", &n);

    connected = (int**) calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++) {
        connected[i] = (int*) calloc(n, sizeof(int));
    }

    int root = 0;
    int parent = 0;
    for(int num = 0; num < n; num++) {
        scanf("%d", &parent);
        if(parent == -1) {
            root = num;
        }
        else {
            connected[parent][num] = 1;
        }
    }

    int deleteNode;
    scanf("%d", &deleteNode);
    if(deleteNode == root) {
        printf("0");

        for(int i = 0; i < n; i++) {
            free(connected[i]);
        }
        free(connected);

        return 0;
    }

    for(int num = 0; num < n; num++) {
        connected[num][deleteNode] = 0;
    }

    dfsThingie(root);
    printf("%d", count);

    for(int i = 0; i < n; i++) {
        free(connected[i]);
    }
    free(connected);

    return 0;
}

void dfsThingie(int parent) {
    int check = 0;
    for(int num = 0; num < n; num++) {
        if(connected[parent][num] == 1) {
            dfsThingie(num);
            check = 1;
        }
    }

    if(check == 0) {
        count++;
    }
}