#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;

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

ll dfs(vvl &adj, ll node, vl &visited) {
    visited[node]=1;
    ll ret=1;
    for (ll nxt: adj[node]) {
        if (visited[nxt]) continue;
        visited[nxt]=1;
        ret += dfs(adj, nxt, visited);
    }
    return ret;
}

void solve(ll testcase){
    ll i, j;
    ll n, m; cin>>n>>m;
    vvl adj(n+1);
    while (m--) {
        ll a, b; cin>>a>>b;
        adj[b].push_back(a);
    }
    vl ans;
    ll max_val=0;
    vl visited(n+1);
    for (i=1;i<=n;i++) {
        for (ll &x: visited) x=0;
        ll cur=dfs(adj, i, visited);
        // cout<<i<<' '<<cur<<endl;
        if (cur>max_val) {
            max_val=cur;
            ans.clear();
        }
        if (cur==max_val) {
            ans.push_back(i);
        }
    }
    for (auto x: ans) cout<<x<<' ';
    cout<<endl;
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