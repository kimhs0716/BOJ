#include <stdio.h>
#include <string.h>
int bigger(char *a, char *b){
    int len1 = strlen(a);
    int len2 = strlen(b);
    if(len1 < len2) return 0;
    if(len1 > len2) return 1;
    if(strcmp(a, b) < 0) return 0;
    return 1;
}
void merge(char arr[][51], int start, int mid, int end){
    char sorted[end - start + 1][51];
    int l = start, r = mid + 1, k = 0;
    while(l <= mid && r <= end){
        if(bigger(arr[l], arr[r]))
            strcpy(sorted[k++], arr[r++]);
        else
            strcpy(sorted[k++], arr[l++]);
    }
    while(l <= mid)
            strcpy(sorted[k++], arr[l++]);
    while(r <= end)
            strcpy(sorted[k++], arr[r++]);
    for(int i = start; i <= end; i++)
        strcpy(arr[i], sorted[i - start]);
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
    scanf("%d", &n);
    char arr[n][51];
    char temp[51];
    for(int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("%s\n", arr[0]);
    for(int i = 0; i < n - 1; i++){
        strcpy(temp, arr[i]);
        if(strcmp(temp, arr[i + 1]) == 0) continue;
        printf("%s\n", arr[i + 1]);
    }
    return 0;
}
