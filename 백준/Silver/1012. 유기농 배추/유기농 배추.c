#include <stdio.h>
int dfs(int, int, int*, int, int, int);
int arr[50][50];
int main() {
    int m, n, k, s;
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        s = 0;
        scanf("%d %d %d", &m, &n, &k);
        for(int j = 0; j < 50; j++)
            for(int h = 0; h < 50; h++) arr[j][h] = 0;
        for(int j = 0; j < k; j++){
            int a, b;
            scanf("%d %d", &a, &b);
            arr[b][a] = 1;
        }
        int count = 0;
        for(int y = 0; y < n; y++)
            for(int x = 0; x < m; x++)
                s += dfs(x, y, &count, m, n, 0);
        printf("%d\n", s);
    }
    return 0;
}
int dfs(int x, int y, int *count, int size_x, int size_y, int pre){
    if(arr[y][x] % 2 == 0) return 0;
    arr[y][x] = 2;
    if(x != 0) dfs(x - 1, y, count, size_x, size_y, 1);
    if(x != size_x - 1) dfs(x + 1, y, count, size_x, size_y, 1);
    if(y != 0) dfs(x, y - 1, count, size_x, size_y, 1);
    if(y != size_y - 1) dfs(x, y + 1, count, size_x, size_y, 1);
    return !pre;
}
