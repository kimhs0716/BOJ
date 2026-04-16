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
// constexpr ll MAX = 65536;

void preprocess() {
    ll i, j, k;
}

//Usage: DSU dsu(V); ll root = dsu._find(node); dsu._union(node,node);
// O(alpha(V))
struct DSU {
    vl par, sz;

    DSU(ll n) {
        par.resize(n+1);
        sz.assign(n+1,1);
        iota(par.begin(),par.end(),0);
    }
    ll _find(ll x) {
        if (par[x]==x) return x;
        return par[x]=_find(par[x]);
        //for RollBack
        //return _find(par[x]);
    }
    pll _union(ll x,ll y){
        x=_find(x);
        y=_find(y);
        if (x==y) return {-1,-1};
        if (sz[x]<sz[y]) swap(x,y);
        par[y]=x;
        sz[x]+=sz[y];
        return {x,y};
    }
    void _delete(ll x, ll y){
        sz[x]-=sz[y];
        par[y]=y;
    }
};

// Usage: LCA lca(V,tree); ll anc = lca.solve(u,v);
// O(logV)
// memo : 0-indexed

struct LCA {
    ll MAXLN;
    vl depth; vvl anc;

    LCA(ll n, vvl& tree){
        ll root = 0;
        depth.assign(n,0);
        MAXLN=1;
        while ((1<<MAXLN)<=n) ++MAXLN;
        anc.assign(MAXLN,vl(n));

        function<void(ll,ll)> dfs4lca = [&](ll node,ll parent) {
            for (ll next: tree[node]) {
                if (next==parent) continue;
                depth[next]=depth[node]+1;
                anc[0][next]=node;
                dfs4lca(next, node);
            }
        };

        dfs4lca(root,-1);
        anc[0][root]=root;
        for (ll i=1;i<MAXLN;++i)
            for (ll j=0;j<n;++j)
                anc[i][j]=anc[i-1][anc[i-1][j]];
    }

    ll solve(ll u, ll v){
        if (depth[u]<depth[v]) swap(u, v);
        ll ret = 0;
        if (depth[u]>depth[v]) {
            for (ll i=MAXLN-1;i>=0;--i)
                if (depth[u]-(1<<i) >= depth[v]) {
                    u=anc[i][u];
                    ret += (1<<i);
                }
        }
        if (u==v) return ret;
        for (ll i=MAXLN-1;i>=0;--i) {
            if (anc[i][u]!=anc[i][v]) {
                u=anc[i][u];
                v=anc[i][v];
                ret += (1<<(i+1));
            }
        }
        return ret+2;
    }
};

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    DSU dsu(n);
    vvl adj(n);
    while (m--) {
        ll x, y; cin>>x>>y;
        --x; --y;
        if (dsu._find(x)==dsu._find(y)) continue;
        dsu._union(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    LCA lca(n, adj);
    ll q; cin>>q;
    while (q--) {
        ll x, y; cin>>x>>y;
        --x; --y;
        cout<<lca.solve(x, y)-1<<endl;
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

