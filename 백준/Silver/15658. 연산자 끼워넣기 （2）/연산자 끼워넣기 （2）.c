#include <stdio.h>
void dfs(int *arr, int res, int a, int b, int c, int d, int *min, int *max, int depth, int goal){
    //printf("%d %d %d %d\n", a, b, c, d);
    if(depth == goal){
        //printf("%d %d %d\n", *max, *min, res);
        *min = (*min > res) ? res : *min;
        *max = (*max < res) ? res : *max;
        return;
    }
    if(a != 0) dfs(arr + 1, res + arr[0], a - 1, b, c, d, min, max, depth + 1, goal);
    if(b != 0) dfs(arr + 1, res - arr[0], a, b - 1, c, d, min, max, depth + 1, goal);
    if(c != 0) dfs(arr + 1, res * arr[0], a, b, c - 1, d, min, max, depth + 1, goal);
    if(d != 0) dfs(arr + 1, res / arr[0], a, b, c, d - 1, min, max, depth + 1, goal);
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int a, b, c, d, min = 1000000000, max = -1000000000;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    dfs(arr + 1, arr[0], a, b, c, d, &min, &max, 0, n - 1);
    printf("%d\n%d", max, min);
    return 0;
}
