#include <stdio.h>
char arr[100][100];
char arr2[100][100];
void dfs(int x, int y, int *count, int size_x, int size_y, char cur){
    if(arr[y][x] != cur) return;
    if(arr[y][x] == '0') return;
    cur = arr[y][x];
    arr[y][x] = '0';
    (*count)++;
    if(x != 0) dfs(x - 1, y, count, size_x, size_y, cur);
    if(x != size_x - 1) dfs(x + 1, y, count, size_x, size_y, cur);
    if(y != 0) dfs(x, y - 1, count, size_x, size_y, cur);
    if(y != size_y - 1) dfs(x, y + 1, count, size_x, size_y, cur);
    return;
}
void dfs2(int x, int y, int *count, int size_x, int size_y, char cur){
    if(arr2[y][x] != cur) return;
    if(arr2[y][x] == '0') return;
    cur = arr2[y][x];
    arr2[y][x] = '0';
    (*count)++;
    if(x != 0) dfs2(x - 1, y, count, size_x, size_y, cur);
    if(x != size_x - 1) dfs2(x + 1, y, count, size_x, size_y, cur);
    if(y != 0) dfs2(x, y - 1, count, size_x, size_y, cur);
    if(y != size_y - 1) dfs2(x, y + 1, count, size_x, size_y, cur);
    return;
}
int main() {
    char inp[100];
    int n;
    int c = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", inp);
        int k = 0;
        while(inp[k]){
            arr[i][k] = inp[k];
            arr2[i][k] = ((inp[k] == 'G') ? 'R' : inp[k]);
            k++;
        }
    }
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++){
            if(arr[y][x] != '0'){
                c++;
                int cc = 0;
                dfs(x, y, &cc, n, n, arr[y][x]);
            }
        }
    printf("%d ", c);
    c = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(arr2[y][x] != '0'){
                c++;
                int cc = 0;
                dfs2(x, y, &cc, n, n, arr2[y][x]);
            }
        }
    }
    printf("%d", c);
    return 0;
}
