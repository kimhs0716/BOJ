#include <stdio.h>
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
void dfs(int, int, int*, int, int);
int arr[25][25];
int sorted[169];
int main() {
    char inp[25];
    int n;
    int c = 0;
    int cc;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", inp);
        int k = 0;
        while(inp[k]){
            arr[i][k] = inp[k] - '0';
            k++;
        }
    }
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++){
            if(arr[y][x] == 1){
                cc = 0;
                c++;
                dfs(x, y, &cc, n, n);
                sorted[c - 1] = cc;
            }
        }
    printf("%d\n", c);
    mergeSort(sorted, 0, c - 1);
    for(int i = 0; i < c; i++)
        printf("%d\n", sorted[i]);
    return 0;
}
void dfs(int x, int y, int *count, int size_x, int size_y){
    if(arr[y][x] % 2 == 0) return;
    arr[y][x] = 2;
    (*count)++;
    if(x != 0) dfs(x - 1, y, count, size_x, size_y);
    if(x != size_x - 1) dfs(x + 1, y, count, size_x, size_y);
    if(y != 0) dfs(x, y - 1, count, size_x, size_y);
    if(y != size_y - 1) dfs(x, y + 1, count, size_x, size_y);
    return;
}
