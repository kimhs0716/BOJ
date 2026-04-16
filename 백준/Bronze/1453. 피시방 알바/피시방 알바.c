#include <stdio.h>
int include(int *arr, int n, int a){
    for(int i = 0; i < n; i++)
        if(arr[i] == a) return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int c = 0;
    int a;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(include(arr, c, a)) continue;
        arr[c++] = a;
    }
    printf("%d", n - c);
    return 0;
}
