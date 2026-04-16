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
// constexpr ll MAX = 10'000'000;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m>>k;
    n++, m++;
    vvl dp(n, vl(m));
    vector ok(n, vector(m, array<bool, 2>()));
    for (i=0;i<n;i++) for (j=0;j<m;j++) ok[i][j] = {1, 1};
    while (k--) {
        ll a, b, c, d; cin>>a>>b>>c>>d;
        if (a>c || b>d) swap(a, c), swap(b, d);
        if (a==c) ok[a][b][0]=0;
        else ok[a][b][1]=0;
    }
    dp[0][0] = 1;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if (i==0 && j==0) continue;
            dp[i][j] = 0;
            if (j>=1 && ok[i][j-1][0]) dp[i][j] += dp[i][j-1];
            if (i>=1 && ok[i-1][j][1]) dp[i][j] += dp[i-1][j];
        }
    }
    cout<<dp[n-1][m-1]<<endl;

    // for (i=0;i<n;i++) {
    //     for (j=0;j<m;j++) {
    //         cout<<dp[i][j]<<' ';
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