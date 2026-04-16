#include <stdio.h>

int main(){
    int t, k, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int arr[15][14] = {0, };
        for(int i = 0; i < 15; i++) arr[i][0] = 1;
        scanf("%d %d", &k, &n);
        for(int i = 0; i <= k; i++){
            for(int j = 1; j < n; j++){
                if(i == 0) arr[i][j] = j + 1;
                else arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
            }
        }
        //for(int i = 0; i < k; i++) { for(int j = 0; j < n; j++) printf("%7d", arr[i][j]); printf("\n"); }
        printf("%d\n", arr[k][n - 1]);
    }
    return 0;
}

