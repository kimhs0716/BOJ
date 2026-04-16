#include <iostream>
typedef long long int lld;
using namespace std;
lld dp[101];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= 6; i++)
        dp[i] = i;
    for(int i = 7; i <= n; i++){
        dp[i] = max(max(dp[i - 1] + 1, 4 * dp[i - 5]), max(2 * dp[i - 3], 3 * dp[i - 4]));
    }
    cout << dp[n] << endl;
    return 0;
}
