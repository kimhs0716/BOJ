#include <stdio.h>
#include <stdlib.h>
void dfs(int x, int y, int *count, int n, int m, char prev);
char arr[100][100];
int visited[100][100];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    int count = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(visited[y][x]) continue;
            count++;
            dfs(x, y, &count, n, m, '-');
            dfs(x, y, &count, n, m, '|');
        }
    }
    printf("%d", count);
    return 0;
}
void dfs(int x, int y, int *count, int n, int m, char prev){
    if(visited[y][x]) return;
    if(prev != arr[y][x]) return;
    visited[y][x] = 1;
    if(x > 0 && prev == '-') dfs(x - 1, y, count, n, m, arr[y][x]);
    if(x < m - 1 && prev == '-') dfs(x + 1, y, count, n, m, arr[y][x]);
    if(y > 0 && prev == '|') dfs(x, y - 1, count, n, m, arr[y][x]);
    if(y < n - 1 && prev == '|') dfs(x, y + 1, count, n, m, arr[y][x]);
    return;
}
