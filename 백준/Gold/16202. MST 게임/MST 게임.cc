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
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

struct UF {
    ll n;
    vl grp, sz;
    UF(ll n) : n(n), grp(n), sz(n, 1) {
        iota(grp.begin(), grp.end(), 0LL);
    }
    ll find(ll x) {
        if (x==grp[x]) return x;
        return grp[x] = find(grp[x]);
    }
    bool same(ll x, ll y) {
        return find(x)==find(y);
    }
    void join(ll x, ll y) {
        if (same(x, y)) return;
        x = find(x);
        y = find(y);
        if (sz[x]<sz[y]) swap(x, y);
        grp[y] = x;
        sz[x] += sz[y];
    }
};

struct Graph {
    ll n;
    vector<tlll> edges;
    Graph(ll n) : n(n) {}
    void add_edge(ll u, ll v, ll x) {
        edges.push_back({x, u, v});
    }
    ll MST(ll idx) {
        UF uf(n);
        ll ret=0;
        for (ll i=idx;i<edges.size();i++) {
            auto [w, u, v] = edges[i];
            if (uf.same(u, v)) continue;
            uf.join(u, v);
            ret += w;
        }
        // cout<<uf.sz<<endl;
        // cout<<uf.grp<<endl;
        if (uf.sz[uf.find(0)] != n) return 0;
        return ret;
    }
};

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m>>k;
    Graph graph(n);
    for (i=1;i<=m;i++) {
        ll u, v; cin>>u>>v;
        graph.add_edge(u-1, v-1, i);
    }
    for (i=0;i<k;i++) cout<<graph.MST(i)<<' ';
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