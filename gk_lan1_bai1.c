#include <stdio.h>
#define MAX 1000

int m, n;
int a[MAX][MAX];
int check[MAX][MAX];

int isSafe(int x, int y, int value) {
    return (x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && a[x][y] == value);
}

int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

int DFS(int x, int y, int val) {
    check[x][y] = 1; 
    int cnt = 1; 

    for (int k = 0; k < 4; k++) {
        if (isSafe(x + row[k], y + col[k], val)) {
            cnt += DFS(x + row[k], y + col[k], val);
        }
    }

    return cnt;
}

int lienThongMax() {
    int max = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j]) {
                int cnt = DFS(i, j, a[i][j]);
                if (cnt > max) {
                    max = cnt;
                }
            }
        }
    }

    return max;
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            check[i][j] = 0; 
        }
    }

    printf("%d\n", lienThongMax());

    return 0;
}
