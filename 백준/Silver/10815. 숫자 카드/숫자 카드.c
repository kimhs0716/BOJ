#include <stdio.h>
#define MAX_SIZE 500000
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
int find(int *arr, int n, int left, int right, int size){
    if(left == right) return arr[left] == n;
    int mid = (left + right) / 2;
    if(arr[mid] == n) return 1;
    if(arr[mid] < n) return find(arr, n, mid + 1, right, size);
    else return find(arr, n, 0, mid, size);
}
int main() {
    int arr[MAX_SIZE] = {0, };
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    int m, a;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &a);
        int found = find(arr, a, 0, n - 1, n);
        printf("%d ", found);
    }
    return 0;
}
