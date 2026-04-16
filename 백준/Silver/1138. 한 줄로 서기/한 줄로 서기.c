#include <stdio.h>
int main(){
    int n, a;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) arr[i] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        for(int i = 0; i <= a; i++)
            if(arr[i] != 0) a++;
        arr[a] = i;
    }
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
