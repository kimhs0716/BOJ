#include <stdio.h>
char arr[20][20];
char visited[26];
int idx = 0;
int r, c;
int max(int a, int b){
    return (a > b) ? a : b;
}
int include(char *arr, char srch, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == srch) return 1;
    }
    return 0;
}
void dfs(int depth, int *m, int x, int y, int dir){
    if(include(visited, arr[y][x], depth)) {
        *m = max(*m, depth);
        return;
    }
    visited[idx++] = arr[y][x];
    if(x < c - 1 && dir != 3) dfs(depth + 1, m, x + 1, y, 1);
    if(x > 0 && dir != 1) dfs(depth + 1, m, x - 1, y, 3);
    if(y < r - 1 && dir != 0) dfs(depth + 1, m, x, y + 1, 2);
    if(y > 0 && dir != 2) dfs(depth + 1, m, x, y - 1, 0);
    visited[--idx] = 0;
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf(" %c", &arr[i][j]);
    int m = 1;
    dfs(0, &m, 0, 0, -1);
    printf("%d", m);
    return 0;
}
