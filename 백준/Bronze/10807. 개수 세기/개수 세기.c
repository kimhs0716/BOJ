#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int arr[201] = {0, };
    for(int i = 0; i < n; i++) {
        int m; scanf("%d", &m);
        arr[m + 100]++;
    }
    int v; scanf("%d", &v);
    printf("%d\n", arr[v + 100]);
    return 0;
}