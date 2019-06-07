#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100005

typedef struct point {
    float x;
    float y;
} node;

typedef struct edge {
    node first;
    node second;
    float dis;
} edge;

int x_compare(const void* a, const void* b)
{
    const node *p = a, *q = b;
    if (p->x - q->x > 0)
        return 1;
    else if (p->x - q->x < 0)
        return -1;
    else
        return 0;
}

int y_compare(const void* a, const void* b)
{
    const node *p = a, *q = b;
    if (p->y - q->y > 0)
        return 1;
    else if (p->y - q->y < 0)
        return -1;
    else
        return 0;
}

float distance(node a, node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

edge min(edge a, edge b) { return a.dis < b.dis ? a : b; }

edge find_nearest(node area[], int l, int h)
{
    edge select_edge;
    if (h < l) {
        printf("error!\n");
        exit(0);
    }
    if (h == l) {
        select_edge.second = area[l];
        select_edge.dis = INFINITY;
        return select_edge;
    }

    if (h == l + 1) {
        select_edge.dis = distance(area[h], area[l]);
        select_edge.first = area[l];
        select_edge.second = area[h];
        return select_edge;
    }
    edge left, right;
    int m = (l + h) / 2;

    left = find_nearest(area, l, m);
    right = find_nearest(area, m + 1, h);
    select_edge = min(left, right);
    float zelta = select_edge.dis;
    float middle_line = (area[m].x + area[m + 1].x) / 2;

    node merge_list[N / 2] = {};
    int i, j, u, v;
    for (i = m, j = m + 1, u = v = 0; i >= l && j <= h; u = v) { //找出位于zelta带里的点
        if (area[i].x + zelta > middle_line) {
            merge_list[v] = area[i];
            i--;
            v++;
        }
        if (area[j].x - zelta < middle_line) {
            merge_list[v] = area[j];
            j++;
            v++;
        }
        if (u == v)
            break;
    }
    qsort(merge_list, v, sizeof(node), y_compare); //按纵坐标排序
    float dis;
    for (i = 0; i < v; i++) { //比较带里的最小距离
        /*
        if (merge_list[i].x < 76.056802 && merge_list[i].x > 76.0568) {
            for (int k = -1; k <= 6; k++) {
                printf("%f\n", merge_list[i + k].x);
            }
        }*/
        for (j = 1; j <= 6 && i + j < v; j++) {
            dis = distance(merge_list[i], merge_list[i + j]);
            if (dis < zelta) {
                select_edge.first = merge_list[i];
                select_edge.second = merge_list[i + j];
                select_edge.dis = zelta = dis;
            }
        }
    }

    return select_edge;
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
    clock_t start, end;
    start = clock();
    qsort(area, n, sizeof(node), x_compare);

    /*
    for (i = 0; i < n; i++) {
        if (area[i].x < 76.056802 && area[i].x > 76.0568) {
            printf("点附近\t");
            for (int k = -6; k <= 6; k++) {
                printf("%f ", area[i + k].x);
            }
            break;
        }
    }
*/
    edge select = find_nearest(area, 0, n - 1);
    printf("分治法: 距离：%f\n1号点\t横坐标：%f，纵坐标：%f\n2号点\t 横坐标：%f，纵坐标：%f\n", select.dis,\
    select.first.x,select.first.y,select.second.x,select.second.y);
    end = clock();
    printf("用时：%f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}
