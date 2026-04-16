#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

void setup() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

void solve(ll tc) {
    ll i, j, k;
    ll n; cin>>n;
    vvl arr(2, vl(n));
    for (auto &x: arr[0]) cin>>x;
    for (auto &x: arr[1]) cin>>x;
    vvl dp(n, vl(3));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[1][0];
    dp[0][2] = 0;
    for (i=1;i<n;i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + arr[0][i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + arr[1][i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
    }
    // for (auto &x: dp) {
    //     for (auto y: x) cout<<y<<' ';
    //     cout<<endl;
    // }
    cout<<*max_element(dp[n-1].begin(), dp[n-1].end())<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}