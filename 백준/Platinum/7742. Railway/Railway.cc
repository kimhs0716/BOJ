#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = int;
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

struct LCA {
    ll n;
    vvp &adj;
    vector<array<ll, 30>> par;
    vl vis, depth, dist;
    LCA(ll n, ll root, vvp &adj) : n(n), adj(adj), vis(n), depth(n), par(n), dist(n) {
        par[root][0] = root;
        dfs(root, 0, 0);
        make_par();
    }
    void dfs(ll cur, ll dep, ll d) {
        vis[cur] = 1;
        depth[cur] = dep;
        dist[cur] = d;
        for (auto [nxt, w]: adj[cur]) {
            if (vis[nxt]) continue;
            par[nxt][0] = cur;
            dfs(nxt, dep+1, d + w);
        }
    }
    void make_par() {
        for (ll j=1;j<30;j++) {
            for (ll i=0;i<n;i++) {
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }
    ll anc(ll u, ll v) {
        if (depth[u] < depth[v]) swap(u, v);
        ll diff = depth[u] - depth[v];
        for (ll i=0; diff; i++) {
            if (diff & 1) u = par[u][i];
            diff >>= 1;
        }
        if (u==v) return u;
        for (ll i = 29; i>=0; i--)
            if (par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        return par[u][0];
    }
    ll solve(ll u, ll v) {
        return dist[u] + dist[v] - 2 * dist[anc(u, v)];
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    ll q; cin>>q;
    vvp adj(n);
    for (i=0;i<n-1;i++) {
        ll u, v, w; cin>>u>>v>>w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    LCA lca(n, 0, adj);
    while (q--) {
        ll x, y; cin>>x>>y;
        cout<<lca.solve(x-1, y-1)<<endl;
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

