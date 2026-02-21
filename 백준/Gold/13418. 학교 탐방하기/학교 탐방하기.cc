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
constexpr ll INF = (ll)1e18+1;

void preprocess() {
    ll i, j;
}

struct UF {
    ll n;
    vl sz, par;
    UF(ll n) : n(n), sz(n, 1), par(n) {
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x==y) return;
        if (sz[x]<sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

struct Graph {
    ll n;
    vvp adj;
    vector<tlll> edges;
    Graph(ll n) : n(n), adj(n) {}
    void add_edge(ll x, ll y, ll w) {
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        edges.push_back({w, x, y});
    }
    ll MST(bool rev=false) {
        UF uf(n);
        sort(edges.begin(), edges.end());
        if (rev) reverse(edges.begin(), edges.end());
        ll ret = 0;
        for (auto [w, x, y] : edges) {
            if (uf.same(x, y)) continue;
            ret += w;
            uf.join(x, y);
        }
        return ret;
    }
};

void solve(ll tc){
    ll i, j;
    ll n, m; cin>>n>>m;
    Graph g(n+1);
    m++;
    while (m--) {
        ll x, y, w; cin>>x>>y>>w;
        g.add_edge(x, y, !w);
    }
    ll a = g.MST(true);
    ll b = g.MST(false);
    cout<<a*a - b*b<<endl;
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
