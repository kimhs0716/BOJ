#include <stdio.h>
#include <stdio.h>
#define MAX_SIZE 1000000
void mergeSort(char *arr, int start, int end){
    int mid = (start + end) / 2;
    if(start < end){
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
void merge(char *arr, int start, int mid, int end){
    char sorted[end - start + 1];
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
int check(char *arr, int depth){
    int ja = 0, mo = 0;
    for(int i = 0; i < depth; i++){
        for(int j = i + 1; j < depth; j++){
            if(arr[i] >= arr[j]) return 0;
        }
    }
    return 1;
}
int check2(char *arr, int depth){
    int ja = 0, mo = 0;
    for(int i = 0; i < depth; i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            mo++;
        else ja++;
    }
    if(ja < 2 || mo < 1) return 0;
    return 1;
}
void dfs(char *arr, int depth, char *list, int size, int goal){
    if(depth == goal){
        if(check2(arr, depth) == 1){
            arr[depth] = '\0';
            printf("%s\n", arr);
        }
    }
    else{
        for(int i = 0; i < size; i++){
            /*
            for(int j = 0; j < depth; j++) printf("%c", arr[j]);
            printf(" %d %d %c\n", depth, i, list[i]);
            */
            arr[depth] = list[i];
            if(check(arr, depth + 1) == 0) continue;
            dfs(arr, depth + 1, list, size, goal);
        }
        arr[depth] = '\0';
    }
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    char arr[b], res[b + 1];
    for(int i = 0; i < b; i++)
        scanf(" %c", &arr[i]);
    mergeSort(arr, 0, b - 1);
    dfs(res, 0, arr, b, a);
    return 0;
}
