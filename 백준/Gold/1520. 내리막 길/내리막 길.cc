#include <iostream>
using namespace std;
int arr[500][500];
int dp[500][500];
int r, c;
int dfs(int x, int y){
    if(dp[y][x] != -1) return dp[y][x];
    int cur = arr[y][x];
    int ret = 0;
    if(x > 0 && arr[y][x - 1] < cur) ret += dfs(x - 1, y);
    if(x < c - 1 && arr[y][x + 1] < cur) ret += dfs(x + 1, y);
    if(y > 0 && arr[y - 1][x] < cur) ret += dfs(x, y - 1);
    if(y < r - 1 && arr[y + 1][x] < cur) ret += dfs(x, y + 1);
    return dp[y][x] = ret;
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]), dp[i][j] = -1;
    dp[r - 1][c - 1] = 1;
    printf("%d\n", dfs(0, 0));
    return 0;
}
