#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 100000
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
    int arr[MAX_SIZE] = {0, };
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    int min = INT_MAX;
    int i = 0, j = 0;
    while(i < n){
        int diff = arr[j] - arr[i];
        if(diff >= m) min = (min > diff) ? diff : min;
        if(diff >= m && i < j)
            i++;
        else j++;
    }
    printf("%d\n", min);
    return 0;
}
