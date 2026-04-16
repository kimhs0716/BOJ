#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using vd = vector<ld>;
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
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
constexpr ll MAX = 1'000'000;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vl w, v;
    while (n--) {
        ll ww, vv, cnt; cin>>ww>>vv>>cnt;
        k=1;
        while (k<=cnt) {
            w.push_back(ww*k);
            v.push_back(vv*k);
            cnt -= k;
            k <<= 1;
        }
        if (cnt) {
            w.push_back(ww*cnt);
            v.push_back(vv*cnt);
        }
    }
    n = w.size();
    vvl dp(n, vl(m+1));
    dp[0][w[0]] = v[0];
    for (i=1;i<n;i++) {
        for (j=0;j<=m;j++) {
            dp[i][j] = dp[i-1][j];
            if (w[i]<=j) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<*max_element(dp[n-1].begin(), dp[n-1].end())<<endl;
    // cout<<w<<endl;
    // cout<<v<<endl;
    // for (i=0;i<n;i++) {
    //     for (j=0;j<=m;j++) cout<<dp[i][j]<<' ';
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