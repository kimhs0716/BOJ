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

bool dfs(vvl &adj, ll cur, ll pa, vector<bool> &win) {
    for (ll ch: adj[cur]) {
        if (ch==pa) continue;
        if (dfs(adj, ch, cur, win)==0) win[cur]=1;
    }
    return win[cur];
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vvl adj(n);
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> win(n);
    dfs(adj, 0, -1, win);
    for (i=0;i<n;i++) {
        if (win[i]) cout<<"donggggas\n";
        else cout<<"uppercut\n";
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