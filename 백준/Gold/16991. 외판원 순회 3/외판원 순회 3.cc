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
using vvd = vector<vd>;
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

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vector<pair<ld, ld>> arr(n); for (auto &[x, y] : arr) cin>>x>>y;
    vvd adj(n, vd(n));
    for (i=0;i<n;i++) {
        auto [x1, y1] = arr[i];
        for (j=0;j<n;j++) {
            auto [x2, y2] = arr[j];
            adj[i][j] = sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
    }
    // cout<<adj<<endl;
    ll total = (1LL<<n) - 1;
    vvd dp(total+1, vd(n, INF));
    dp[1][0] = 0;
    for (ll mask=0;mask<(1LL<<n);mask++) {
        for (ll u=0;u<n;u++) {
            if ((mask>>u)&1) {
                for (ll v=0;v<n;v++) {
                    if ((mask>>v)&1) continue;
                    if (u==v) continue;
                    dp[mask|(1LL<<v)][v] = min(dp[mask|(1LL<<v)][v], dp[mask][u] + adj[u][v]);
                }
            }
        }
    }
    ld ans = INF;
    for (i=0;i<n;i++) {
        // cout<<i<<": "<<dp[total][i]<<endl;
        ans = min(ans, dp[total][i] + adj[i][0]);
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
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

