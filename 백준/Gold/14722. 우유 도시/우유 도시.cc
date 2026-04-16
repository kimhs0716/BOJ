#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

void setup() {
#ifdef KIMHS
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

template <typename T>
istream& operator>>(istream &is, vector<T> &arr) {
    for (auto &x: arr) is>>x;
    return is;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j, k;
    ll n; cin>>n;
    vvl arr(n, vl(n));
    cin>>arr;
    ll ans=0;
    vector dp(n, vector<array<ll, 3>>(n));
    if (arr[0][0]==0) dp[0][0][1]++;
    for (i=1;i<n;i++) {
        dp[0][i] = dp[0][i-1];
        if (arr[0][i]==0) dp[0][i][1] = max(dp[0][i][1], dp[0][i-1][0]+1);
        if (arr[0][i]==1 && dp[0][i-1][1]) dp[0][i][2] = max(dp[0][i][2], dp[0][i-1][1]+1);
        if (arr[0][i]==2 && dp[0][i-1][2]) dp[0][i][0] = max(dp[0][i][0], dp[0][i-1][2]+1);
    }
    for (i=1;i<n;i++) {
        dp[i][0] = dp[i-1][0];
        if (arr[i][0]==0) dp[i][0][1] = max(dp[i][0][1], dp[i-1][0][0]+1);
        if (arr[i][0]==1 && dp[i-1][0][1]) dp[i][0][2] = max(dp[i][0][2], dp[i-1][0][1]+1);
        if (arr[i][0]==2 && dp[i-1][0][2]) dp[i][0][0] = max(dp[i][0][0], dp[i-1][0][2]+1);
        for (j=1;j<n;j++) {
            for (k=0;k<3;k++) dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
            if (arr[i][j]==0) dp[i][j][1] = max({dp[i][j][1], dp[i-1][j][0]+1, dp[i][j-1][0]+1});
            if (arr[i][j]==1) {
                if (dp[i-1][j][1])
                    dp[i][j][2] = max(dp[i][j][2], dp[i-1][j][1]+1);
                if (dp[i][j-1][1])
                    dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][1]+1);
            }
            if (arr[i][j]==2) {
                if (dp[i-1][j][2])
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][2]+1);
                if (dp[i][j-1][2])
                    dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][2]+1);
            }
        }
    }
    cout<<max({dp[n-1][n-1][0], dp[n-1][n-1][1], dp[n-1][n-1][2]})<<endl;
    // for (auto &x: dp) {
    //     for (auto &y: x) cout<<y[0]<<y[1]<<y[2]<<' ';
    //     cout<<endl;
    // }
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    // cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}