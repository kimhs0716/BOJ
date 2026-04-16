#include <stdio.h>
typedef struct Person{
    int age;
    char name[101];
} person;
int bigger(person a, person b){
    if(a.age > b.age) return 1;
    if(a.age < b.age) return 0;
    return 0;
}
void merge(person *arr, int start, int mid, int end){
    person sorted[end - start + 1];
    int l = start, r = mid + 1, k = 0;
    person temp;
    while(l <= mid && r <= end){
        if(bigger(arr[l], arr[r])){
            sorted[k].age = arr[r].age;
            strcpy(sorted[k++].name, arr[r++].name);
        }
        else{
            sorted[k].age = arr[l].age;
            strcpy(sorted[k++].name, arr[l++].name);
        }
    }
    while(l <= mid){
            sorted[k].age = arr[l].age;
            strcpy(sorted[k++].name, arr[l++].name);
        }
    while(r <= end){
            sorted[k].age = arr[r].age;
            strcpy(sorted[k++].name, arr[r++].name);
        }
    for(int i = start; i <= end; i++){
        arr[i].age = sorted[i - start].age;
        strcpy(arr[i].name, sorted[i - start].name);
    }
}
void mergeSort(person *arr, int start, int end){
    if(start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int main(){
    int n;
    scanf("%d", &n);
    person arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d %s", &arr[i].age, arr[i].name);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
    return 0;
}
