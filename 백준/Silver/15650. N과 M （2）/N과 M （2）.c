#include <stdio.h>
int dup_check(int *arr, int n, int m){
    for(int i = 0; i < n; i++)
        if(arr[i] == m) return 1;
    return 0;
}
void dfs(int *arr, int range, int depth, int goal){
    if(goal == depth){
        for(int i = 0; i < depth; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = (depth == 0) ? 1 : (arr[depth - 1] + 1); i <= range; i++){
        if(dup_check(arr, depth, i)) continue;
        arr[depth] = i;
        dfs(arr, range, depth + 1, goal);
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[m];
    dfs(arr, n, 0, m);
    return 0;
}
