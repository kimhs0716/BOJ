#include <stdio.h>
int arr[100][100];
void check(int node, int *count, int size){
    for(int i = 0; i < size; i++)
        if(arr[i][node] == 2) return;
    (*count)++;
    for(int i = 0; i < size; i++){\
        if(arr[node][i] == 1){
            arr[i][node] = 2;
            check(i, count, size);
        }
    }
}
int main() {
    int n, m;
    int a, b;
    int res = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = 0;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        a--;
        b--;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    int count = -1;
    check(0, &count, n);
    printf("%d", count);
    return 0;
}
