#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    int dp[n][2];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i][0] = dp[i][1] = 0;
    }
    if(n == 1){
        cout << arr[0] << endl;
        return 0;
    }
    dp[0][0] = arr[0];
    int M = arr[0];
    dp[1][0] = max(0, arr[0]) + arr[1];
    dp[1][1] = arr[1];
    M = max(M, max(dp[1][0], dp[1][1]));
    for(int i = 2; i < n; i++){
        dp[i][0] = max(0, dp[i - 1][0]) + arr[i];
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0]) + arr[i];
        M = max(M, max(dp[i][0], dp[i][1]));
    }
    cout << M << endl;
    return 0;
}
