#include <stdio.h>
int min(int a, int b){
    return (a < b) ? a : b;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    char str[m];
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        for(int j = 0; j < m; j++)
            arr[i][j] = str[j] - '0';
    }
    int max = 0;
    for(int size = 1; size <= min(n, m); size++){
        for(int y = 0; y <= n - size; y++){
            for(int x = 0; x <= m - size; x++){
                if(arr[y][x] != arr[y + size - 1][x] || arr[y][x] != arr[y][x + size - 1]\
                   || arr[y][x] != arr[y + size - 1][x + size - 1]) continue;
                max = (max < size) ? size : max;
            }
        }
    }
    printf("%d", max * max);
    return 0;
}
