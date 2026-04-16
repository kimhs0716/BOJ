#include <stdio.h>
int bigger(int *a, int *b){
    if(a[0] > b[0]) return 1;
    if(a[0] < b[0]) return 0;
    if(a[1] > b[1]) return 1;
    return 0;
}
void merge(int arr[][2], int start, int mid, int end){
    int sorted[end - start + 1][2];
    int l = start, r = mid + 1, k = 0;
    while(l <= mid && r <= end){
        if(bigger(arr[l], arr[r])){
            sorted[k][0] = arr[r][0];
            sorted[k++][1] = arr[r++][1];
        }
        else{
            sorted[k][0] = arr[l][0];
            sorted[k++][1] = arr[l++][1];
        }
    }
    while(l <= mid){
        sorted[k][0] = arr[l][0];
        sorted[k++][1] = arr[l++][1];
    }
    while(r <= end){
        sorted[k][0] = arr[r][0];
        sorted[k++][1] = arr[r++][1];
    }
    for(int i = start; i <= end; i++){
        arr[i][0] = sorted[i - start][0];
        arr[i][1] = sorted[i - start][1];
    }
}
void mergeSort(int arr[][2], int start, int end){
    if(start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int main(){
    int n;
    int temp[2];
    scanf("%d", &n);
    int arr[n][2];
    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i][0], arr[i][1]);
    return 0;
}
