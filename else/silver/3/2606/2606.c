#include <stdio.h>
#include <stdlib.h>

int n;
int** net;
int* netVisited;

void dfsThingie(int computerNum);

int main() {
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    net = (int**) calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++) {
        net[i] = (int*) calloc(n, sizeof(int));
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        net[a - 1][b - 1] = 1;
        net[b - 1][a - 1] = 1;
    }

    netVisited = (int*) calloc(n, sizeof(int));

    dfsThingie(0);

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(netVisited[i]) {
            count++;
        }
    }

    printf("%d", count - 1);

    for(int i = 0; i < n; i++) {
        free(net[i]);
    }
    free(net);
    free(netVisited);
}

void dfsThingie(int rowComputerIndex) {
    netVisited[rowComputerIndex] = 1;
    for(int colComputerIndex = 0; colComputerIndex < n; colComputerIndex++) {
        if(net[rowComputerIndex][colComputerIndex] == 1 && !netVisited[colComputerIndex]) {
            dfsThingie(colComputerIndex);
        }
    }
}