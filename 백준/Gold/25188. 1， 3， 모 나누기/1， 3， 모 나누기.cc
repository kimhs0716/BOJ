#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;

#define endl '\n'

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

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    vector<array<ll, 6>> dp(n);
    dp[0][0]=arr[0];
    dp[0][1]=0;
    for (i=2;i<6;i++) dp[0][i]=-INF;
    for (i=1;i<n;i++) {
        dp[i][0] = dp[i-1][0] + arr[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + arr[i];
        dp[i][3] = max(dp[i-1][2], dp[i-1][3]);
        dp[i][4] = max(dp[i-1][3], dp[i-1][4]) + arr[i];
        dp[i][5] = max(dp[i-1][4], dp[i-1][5]);
        // dp[i][6] = max(dp[i-1][5], dp[i-1][6]) + arr[i];
    }
    ll ans=-INF;
    for (i=0;i<n;i++) for (j=0;j<6;j++) ans=max(ans, dp[i][j]);
    cout<<ans<<endl;
    // for (j=0;j<6;j++) {
    //     for (i=0;i<n;i++) {
    //         cout<<setw(2);
    //         if (dp[i][j] > -1e9) cout<<dp[i][j]<<' ';
    //         else cout<<"-I ";
    //     }
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