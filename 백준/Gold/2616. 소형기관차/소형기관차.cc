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
using vp = vector<pll>;
using vvp = vector<vp>;
using tlll = array<ll, 3>;

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

template <typename T>
ostream& operator<<(ostream &os, vector<T> &arr) {
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    vl pre(n+1);
    for (i=1;i<=n;i++) pre[i] += pre[i-1] + arr[i-1];
    ll k; cin>>k;
    vvl dp(n, vl(3, -1));
    dp[k-1][0] = pre[k];
    // cout<<pre<<endl;
    for (i=k;i<n;i++) {
        dp[i][0] = max(dp[i-1][0], pre[i+1] - pre[i-k+1]);
        if (i >= 2*k-1) dp[i][1] = max(dp[i-k][0] + pre[i+1] - pre[i-k+1], dp[i-1][1]);
        if (i >= 3*k-1) dp[i][2] = max(dp[i-k][1] + pre[i+1] - pre[i-k+1], dp[i-1][2]);
    }
    // for (i=0;i<n;i++) {
    //     for (j=0;j<3;j++) {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][2]<<endl;
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