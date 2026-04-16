#include <stdio.h>
int max(int a, int b);
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int dp[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    dp[0] = arr[0];
    int M = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(0, dp[i - 1]) + arr[i];
        M = max(M, dp[i]);
    }
    printf("%d\n", M);
    return 0;
}
int max(int a, int b){
    return (a > b) ? a : b;
}
