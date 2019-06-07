#include <stdio.h>
#define up 0
#define left 1
#define left_up 2

typedef struct {
    int num;
    int dir;
} node;

main() {
    char a[100], b[100];
    node map[100][100] = {};
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int i, j;
    for (i = 1; a[i]; i++) {
        for (j = 1; b[j]; j++) {
            if (a[i] == b[j]) {
                map[i][j].num = map[i - 1][j - 1].num + 1;
                map[i][j].dir = left_up;
            } else {
                if (map[i - 1][j].num > map[i][j - 1].num) {
                    map[i][j].num = map[i - 1][j].num;
                    map[i][j].dir = up;
                } else {
                    map[i][j].num = map[i][j - 1].num;
                    map[i][j].dir = left;
                }
            }
        }
    }
    i--;
    j--;
    int length = map[i][j].num;
    printf("length:%d\n", length);
    char result[100] = {};
    while (map[i][j].num) {
        switch (map[i][j].dir) {
            case up:
                i--;
                break;

            case left:
                j--;
                break;

            default:
                result[length] = a[i];
                length--;
                i--;
                j--;
                break;
        }
    }
    printf("substring: %s\n", result + 1);
}