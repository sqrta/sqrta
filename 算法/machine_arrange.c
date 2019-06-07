#include <stdio.h>

int machine_len[100] = {};
int work_len[100] = {};
int machine_arrange[100] = {};
int machine_sign[100] = {};
int n;
int min = 66666;
int k;

int cal() {
    int i, tmp = 0;
    for (i = 1; i <= k; i++) {
        if (machine_len[i] > tmp) tmp = machine_len[i];
    }
    return tmp;
}

void find(int depth) {
    if (depth > n) {
        int tmp = cal();
        if (tmp < min) {
            min = tmp;
            for (int i = 1; i <= n; i++) {
                machine_arrange[i] = machine_sign[i];
            }
        }
    }

    else {
        for (int i = 1; i <= k; i++) {  //尝试将编号为depth的任务分配给每一个机器
            if (machine_len[i] + work_len[depth] < min) {
                machine_sign[depth] = i;
                machine_len[i] += work_len[depth];
                find(depth + 1);
                machine_sign[depth] = 0;
                machine_len[i] -= work_len[depth];
            }
        }
    }
}

void sort(int a[], int length) {  //从大到小排序
    int i, j, k;

    for (i = 0; i < length - 1; i++) {
        for (k = i, j = k + 1; j < length; j++) {
            if (a[j] > a[k]) k = j;
        }
        if (k != i) {
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    int result[100][100] = {};
    int i, j;
    for (i = 1; i <= n; i++) {
        scanf("%d,", &work_len[i]);
    }
    sort(work_len + 1, n);
    int flag = 1;
    for (i = 1, j = 1; i <= n; i++) {
        machine_len[j] += work_len[i];
        // printf("%d\n", j);
        if (flag) {
            if (j == k)
                flag = 0;
            else
                j++;
        } else {
            if (j == 1)
                flag = 1;
            else
                j--;
        }
    }
    min = cal();
    // min=127;
    for (i = 1; i <= n; i++) printf("%d ", work_len[i]);
    printf("\n初步解：%d\n", min);

    for (i = 1; i <= k; i++) {
        machine_len[i] = work_len[i];
        machine_sign[i] = i;
    }

    find(k + 1);
    printf("近似解：%d\n", min);
    for (i = 1; i <= k; i++) {
        machine_len[i] = 0;
        machine_sign[i] = 0;
    }
    machine_len[1]=work_len[1];
    machine_sign[1]=1;
    find(2);
    printf("最终解：%d\n", min);
    for (i = 1; i <= n; i++) {
        int u = machine_arrange[i];
        result[u][result[u][0] + 1] = i;
        result[u][0]++;
    }
    for (i = 1; i <= k; i++) {
        printf("%d号机器做：", i);
        for (int j = 1; j <= result[i][0]; j++) printf("%d ", work_len[result[i][j]]);
        printf("\n");
    }
    printf("用时%d\n", min);
}