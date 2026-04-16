#include <stdio.h>
#define MAX_SIZE 10
void mergeSort(int *arr, int start, int end){
    int mid = (start + end) / 2;
    if(start < end){
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
void merge(int *arr, int start, int mid, int end){
    int sorted[end - start + 1];
    int l = start, r = mid + 1, k = 0;
    while(1){
        if(arr[l] > arr[r]) sorted[k++] = arr[r++];
        else sorted[k++] = arr[l++];
        if(l > mid) {
            while(r <= end) sorted[k++] = arr[r++];
            break;
        }
        else if(r > end){
            while(l <= mid) sorted[k++] = arr[l++];
            break;
        }
    }
    for(int i = start; i <= end; i++)
        arr[i] = sorted[i - start];
}
int include(int *arr, int n, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == n) return 1;
    }
    return 0;
}
int dfs(int depth, int *res, int *arr, int n){
    if(depth == n) return 1;
    int idx = depth;
    while(res[idx] != -1) idx++;
    for(int i = 0; i < n; i++){
        int j = arr[i];
        if(include(res, j, 2 * n)) continue;
        if(idx + j + 1 >= 2 * n) continue;
        if(res[idx + j + 1] != -1) continue;
        res[idx] = res[idx + j + 1] = j;
        if(dfs(depth + 1, res, arr, n)) return 1;
        res[idx] = res[idx + j + 1] = -1;
    }
    return 0;
}
int main() {
    int arr[MAX_SIZE] = {0, };
    int n;
    int res[2 * MAX_SIZE];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        res[2 * i] = res[2 * i + 1] = -1;
    }
    mergeSort(arr, 0, n - 1);
    if(dfs(0, res, arr, n) == 0){
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < 2 * n; i++)
        printf("%d ", res[i]);
    return 0;
}
