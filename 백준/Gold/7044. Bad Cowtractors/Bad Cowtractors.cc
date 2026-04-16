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
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;

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

//Usage: ll mst = kruskal(V, adj);
// O(ElogE)
ll kruskal(ll n,vector<vector<pll>>& adj){
    DSU dsu(n);
    ll ret = 0;
    vector<pair<ll, pll>> e;
    for(ll i= 0; i < n; i++)
        for(ll j=0; j < adj[i].size(); j++)
            e.push_back({adj[i][j].second, {i, adj[i][j].first}});
    sort(e.rbegin(), e.rend());
    for(ll i=0; i < e.size(); i++){
        ll x = e[i].second.first,y = e[i].second.second;
        if(dsu._find(x) != dsu._find(y)){
            dsu._union(x, y);
            ret += e[i].first;
        }
    }
    ll p=dsu._find(0);
    for(ll i=1;i<n;i++){
        if(dsu._find(i)!=p) return -1;
    }
    return ret;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vector<vector<pll>> adj(n);
    while (m--) {
        ll u, v, w; cin>>u>>v>>w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout<<kruskal(n, adj)<<endl;
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