#include <bits/stdc++.h>

#include <utility>
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
ostream& operator<<(ostream &os, vector<T> arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;
constexpr ll MAX = 500'000;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll r, c; cin>>r>>c;
    vvl dp(r, vl(c, INF));
    dp[r-1][c-1] = 0;
    ll m; cin>>m;
    map<pll, ll> fuel;
    while (m--) {
        ll x, y, z; cin>>x>>y>>z;
        fuel[{x-1, y-1}] = z;
    }
    for (ll k=r+c-3;k>=0;k--) {
        for (i=r-1;i>=0;i--) {
            j = k-i;
            if (j<0 || j>=c) continue;
            if (i!=r-1) dp[i][j] = min(dp[i][j], dp[i+1][j]);
            if (j!=c-1) dp[i][j] = min(dp[i][j], dp[i][j+1]);
            dp[i][j]++;
            if (fuel.count({i, j}))
                dp[i][j] = max(0LL, dp[i][j] - fuel[{i, j}]);
        }
    }
    cout<<dp[0][0]<<endl;
    // for (auto &x : dp) cout<<x<<endl;
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
