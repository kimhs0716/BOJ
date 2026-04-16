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
int main() {
    int arr[3] = {0, };
    for(int i = 0; i < 3; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, 3 - 1);
    printf("%d", arr[1]);
    return 0;
}
