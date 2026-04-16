#include <iostream>
#include <cstdlib>
using namespace std;
int n, m;
int arr[8];
int temp[8];
int compare(const void *a, const void *b){
    const int *x = (int *)a;
    const int *y = (int *)b;

    if(*x > *y) return 1;
    if(*x < *y) return -1;
    return 0;
}
int __max(int d){
    int res = 0;
    for(int i = 0; i < d; i++)
        res = max(res, temp[i]);
    return res;
}
void dfs(int depth){
    if(depth == m){
        for(int i = 0; i < m; i++)
            printf("%d ", temp[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++){
        if(__max(depth) > arr[i]) continue;
        temp[depth] = arr[i];
        dfs(depth + 1);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    qsort(arr, n, sizeof(int), compare);
    dfs(0);
    return 0;
}
