#include <stdio.h>
#include <math.h>
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
    int sorted[MAX_SIZE];
    int l = start, r = mid + 1, k = start;
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
        arr[i] = sorted[i];
}
int main() {
    int arr[MAX_SIZE] = {0, };
    int n, c = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    int i = 0, j = n - 1, s, m = 2000000001;
    int x, y;
    while(i != j){
        s = arr[i] + arr[j];
        if(abs(s) < m){
            m = abs(s);
            x = i;
            y = j;
        }
        if(s < 0) i++;
        else j--;
    }
    printf("%d %d", arr[x], arr[y]);
    return 0;
}
