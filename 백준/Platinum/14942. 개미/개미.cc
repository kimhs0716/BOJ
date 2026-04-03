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
constexpr ll INF = 1e18;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    vvp adj(n), table(17, vp(n));
    for (i=0;i<n-1;i++) {
        ll u, v, w; cin>>u>>v>>w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    function<void(ll, ll, ll)> dfs = [&adj, &table, &dfs](ll cur, ll par, ll d) {
        table[0][cur] = {par, d};
        for (auto [nxt, w] : adj[cur]) {
            if (nxt == par) continue;
            dfs(nxt, cur, w);
        }
    };
    dfs(0, 0, 0);
    for (i=1;i<17;i++) {
        for (j=0;j<n;j++) {
            auto &[p, d] = table[i][j];
            p = table[i-1][table[i-1][j].first].first;
            d = table[i-1][table[i-1][j].first].second + table[i-1][j].second;
        }
    }
    for (i=0;i<n;i++) {
        ll t = i;
        for (j=16;j>=0;j--) {
            if (table[j][t].second <= arr[i]) {
                arr[i] -= table[j][t].second;
                t = table[j][t].first;
            }
        }
        cout<<t+1<<endl;
    }
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
