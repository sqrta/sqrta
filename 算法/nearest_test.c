#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100005

typedef struct point {
    float x;
    float y;
} node;

float distance(node a, node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void main()
{
    int n;
    node area[N] = {};
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%f %f", &area[i].x, &area[i].y);
    }
    int j;
    float min = INFINITY;
    int p, q;
    clock_t start, end;
    start = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            float tmp = distance(area[i], area[j]);
            if (tmp < min) {
                min = tmp;
                p = i;
                q = j;
            }
        }
    }

    printf("暴力法：\n 1点坐标：%f\t%f,%f\n2点坐标%f,%f\n", min, area[p].x, area[p].y, area[q].x, area[q].y);
    end = clock();
    printf("用时：%f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}