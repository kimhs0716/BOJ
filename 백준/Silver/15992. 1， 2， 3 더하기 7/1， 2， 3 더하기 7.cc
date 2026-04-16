#include <iostream>
#include <vector>
#define mod 1000000009
using namespace std;
int dp[1001][1001];
vector<pair<int, int>> v;
int main(){
    int t; cin >> t;
    int nM, mM;
    nM = mM = 0;
    for(int i = 0; i < t; i++) {
        int n, m; cin >> n >> m;
        nM = max(nM, n);
        mM = max(mM, m);
        v.push_back(make_pair(n, m));
    }
    dp[1][1] = dp[2][1] = dp[3][1] = dp[2][2] = dp[3][3] = 1;
    dp[3][2] = 2;
    for(int i = 2; i <= mM; i++){
        for(int j = 4; j <= nM; j++){
            dp[j][i] = (dp[j - 1][i - 1] + dp[j - 2][i - 1]) % mod + dp[j - 3][i - 1];
            dp[j][i] %= mod;
        }
    }
    for(auto iter = v.begin(); iter < v.end(); iter++){
        cout << dp[(*iter).first][(*iter).second] << "\n";
    }
    return 0;
}
