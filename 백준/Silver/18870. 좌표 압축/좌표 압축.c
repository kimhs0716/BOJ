#include <stdio.h>
int bigger(int a, int b){
    if(a > b) return 1;
    return 0;
}
void merge(int *arr, int start, int mid, int end){
    int sorted[end - start + 1];
    int l = start, r = mid + 1, k = 0;
    while(l <= mid && r <= end){
        if(bigger(arr[l], arr[r])){
            sorted[k++] = arr[r++];
        }
        else{
            sorted[k++] = arr[l++];
        }
    }
    while(l <= mid){
        sorted[k++] = arr[l++];
    }
    while(r <= end){
        sorted[k++] = arr[r++];
    }
    for(int i = start; i <= end; i++){
        arr[i] = sorted[i - start];
    }
}
void mergeSort(int *arr, int start, int end){
    if(start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int count(int *arr, int n, int size){
    int start = 0, end = size - 1, mid;
    while(1){
        mid = (start + end) / 2;
        //printf("%d %d %d %d %d %d\n", start, mid, end, arr[mid], arr[mid + 1], n);
        if(arr[mid] < n && arr[mid + 1] == n) break;
        if(mid == 0 && arr[mid] == n){
            mid--;
            break;
        }
        if(arr[mid] < n) start = mid;
        else if(arr[mid] >= n) end = mid;
    }
    return mid + 1;
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n], original[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        original[i] = arr[i];
    }

    mergeSort(arr, 0, n - 1);

    /*
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", original[i]);
    }
    */

    int new_arr[n], c = 1, temp;
    temp = arr[0];
    new_arr[0] = arr[0];
    for(int i = 1; i < n; i++){
        if(temp == arr[i]) continue;
        temp = arr[i];
        new_arr[c++] = temp;
    }

    /*
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < c; i++){
        printf("%d ", new_arr[i]);
    }
    */

    for(int i = 0; i < n; i++){
        printf("%d ", count(new_arr, original[i], c));
    }

    return 0;
}
