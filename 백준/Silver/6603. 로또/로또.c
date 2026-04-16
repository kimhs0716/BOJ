#include <stdio.h>
int dup(int *arr, int size){
    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++)
            if(arr[i] == arr[j]) return 1;
    return 0;
}
void dfs(int *arr, int depth, int *num_arr, int size){
    if(depth == 6){
        for(int i = 0; i < 6; i++)
            printf("%d ", num_arr[arr[i]]);
        printf("\n");
        return;
    }
    for(int i = (depth == 0) ? 0 : (arr[depth - 1] + 1); i < size; i++){
        arr[depth] = i;
        if(dup(arr, depth + 1)) continue;
        dfs(arr, depth + 1, num_arr, size);
    }
    return;
}
int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        int arr[n];
        int res[6];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        dfs(res, 0, arr, n);
        printf("\n");
    }
    return 0;
}
