#include <stdio.h>
double max(double a, double b){
    return (a < b) ? b : a;
}
int main(){
    int n;
    scanf("%d", &n);
    double arr[n];
    double dp[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &arr[i]);
        dp[i] = 0.0;
    }
    double m = 0.0;
    dp[0] = arr[0];
    for(int i = 0; i < n; i++){
        if(i == 0) dp[i] = arr[i];
        else dp[i] = max(dp[i - 1], 1.0) * arr[i];
        m = max(m, dp[i]);
    }
    printf("%.3lf", m);
    return 0;
}
