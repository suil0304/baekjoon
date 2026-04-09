#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[6];
    char state[6];
} Employee;

int compare(const void* a, const void* b);

int main() {
    int n;
    scanf("%d", &n);

    Employee* logs;
    logs = (Employee*) malloc(sizeof(Employee) * n);

    for(int i = 0; i < n; i++) {
        scanf("%s %s", logs[i].name, logs[i].state);
    }

    qsort(logs, n, sizeof(Employee), compare);

    int enterCount = 0;
    int leaveCount = 0;

    if(strcmp(logs[0].state, "enter") == 0) {
        enterCount++;
    }
    else {
        leaveCount++;
    }

    char prevName[6];
    strcpy(prevName, logs[0].name);

    for(int i = 1; i <= n; i++) {
        if(strcmp(prevName, logs[i].name) != 0) {
            if(enterCount > leaveCount) {
                printf("%s\n", prevName);
                if(i == n) {
                    break;
                }
            }
            strcpy(prevName, logs[i].name);
            enterCount = 0;
            leaveCount = 0;
        }

        if(strcmp(logs[i].state, "enter") == 0) {
            enterCount++;
        }
        else {
            leaveCount++;
        }
    }

    free(logs);

    return 0;
}

int compare(const void* a, const void* b) {
    return strcmp(((Employee*) b)->name, ((Employee*) a)->name);
}

// int lowerBound(char** strArray, int low, int high, char* str, _CoreCrtNonSecureSearchSortCompareFunction compareFunction) {
//     if(low == high) {
//         return low;
//     }

//     int mid = low + (high - low) / 2;

//     if(compareFunction(strArray[mid], str) >= 0) {
//         high = mid;
//     }
//     else {
//         low = mid + 1;
//     }

//     return lowerBound(strArray, low, high, str, compareFunction);
// }

// int upperBound(char** strArray, int low, int high, char* str, _CoreCrtNonSecureSearchSortCompareFunction compareFunction) {
//     if(low == high) {
//         return high - 1;
//     }

//     int mid = low + (high - low) / 2;

//     if(compareFunction(strArray[mid], str) > 0) {
//         high = mid;
//     }
//     else {
//         low = mid + 1;
//     }

//     return upperBound(strArray, low, high, str, compareFunction);
// }