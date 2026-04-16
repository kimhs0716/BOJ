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

template <typename T>
ostream& operator<<(ostream &os, vector<T> &arr) {
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j, k;
    ld aa, bb; cin>>aa>>bb;
    ld ab = 1-aa, ba = 1-bb;

    vector dp(11, vector<ld>(11, 0));
    dp[0][0] = 1;
    for (i=0;i<=10;i++) {
        for (j=0;j<=10;j++) {
            if ((i+j-1)%4 < 2) {
                if (i>=1) dp[i][j] += dp[i-1][j] * aa;
                if (j>=1) dp[i][j] += dp[i][j-1] * ab;
            }
            else {
                if (i>=1) dp[i][j] += dp[i-1][j] * ba;
                if (j>=1) dp[i][j] += dp[i][j-1] * bb;
            }
        }
    }
    ld p = dp[10][10] * aa*ba / (aa*ba + ab*bb);
    for (i=0;i<=9;i++) {
        if (i%4 < 2) p += dp[10][i] * ba;
        else p += dp[10][i] * aa;
    }
    ld q=1-p;
    // cout<<p<<endl;
    cout<<fixed;
    cout.precision(10);
    cout<<(p*p*p*p * (1 + 4*q + 10*q*q + 20*q*q*q))<<endl;
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