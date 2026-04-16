#include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")

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
constexpr ll INF = 104857601;

void preprocess() {
    ll i, j;
}

struct UF {
    vl grp, sz;
    UF (ll n) : sz(n+1, 1), grp(n+1) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll find(ll x) {
        if (x==grp[x]) return x;
        return grp[x] = find(grp[x]);
    }
    void join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x==y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        grp[y] = x;
    }
    bool same(ll x, ll y) {
        return find(x)==find(y);
    }
};

struct Graph {
    ll n;
    vvp adj;
    vector<tlll> edges;
    Graph (ll _n) : n(_n), adj(n) {}
    void add_edge(ll u, ll v, ll w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.push_back({u, v, w});
    }
    ll MST() {
        sort(edges.begin(), edges.end(), [](const tlll &a, const tlll &b) {
            return a[2] < b[2];
        });
        UF uf(n);
        ll ret = 0;
        for (auto &[u, v, w] : edges) {
            if (uf.same(u, v)) continue;
            uf.join(u, v);
            ret += w;
        }
        return ret;
    }
};

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    Graph g(n+1);
    for (i=1;i<=n;i++) {
        ll x; cin>>x;
        g.add_edge(0, i, x);
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            ll w; cin>>w;
            if (i==j) continue;
            g.add_edge(i, j, w);
        }
    }
    cout<<g.MST()<<endl;
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