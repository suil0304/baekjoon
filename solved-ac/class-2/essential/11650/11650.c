#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

int compare(const void* a, const void* b);

int main() {
    int n;
    scanf("%d", &n);

    Point* points;
    points = (Point*) malloc(sizeof(Point) * n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qsort(points, n, sizeof(Point), compare);

    for(int i = 0; i < n; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    free(points);

    return 0;
}

int compare(const void* a, const void* b) {
    if(((Point*) a)->x != ((Point*) b)->x) {
        return ((Point*) a)->x - ((Point*) b)->x;
    }
    return ((Point*) a)->y - ((Point*) b)->y;
}