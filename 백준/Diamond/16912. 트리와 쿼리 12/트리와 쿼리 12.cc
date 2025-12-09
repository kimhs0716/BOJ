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
        // return par[x]=_find(par[x]);
        // for RollBack
        return _find(par[x]);
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

//Usage: vector<tlll> query; OFDC ofdc(V, #query, query);
//O(QlogQ * alpha(V))
struct OFDC{
    vector<tlll>query;
    vector<vector<pll>> tree;
    map<pll,ll>connected_time;
    ll n, q; vl ans;
    DSU dsu;

    OFDC(ll n, ll q,vector<tlll>&query): n(n), q(q), query(query), tree(4*(q+1)), dsu(n+1) {
        for(ll i=0;i<q;i++){
            auto&[type,u,v]=query[i];
            if(u>v)swap(u,v);
            if(type==1) connected_time[{u,v}]=i; //union
            else if(type==2){ //delete
                update(1,0,q-1,connected_time[{u,v}],i-1,{u,v});
                connected_time.erase({u,v});
            }
        }
        for(auto&[edge,time]:connected_time){
            auto&[u,v]=edge;
            update(1,0,q-1,time,q-1,{u,v});
        }
        dfs(1,0,q-1);
    }

    void update(ll node, ll s, ll e, ll l, ll r, pll edge){
        if (l>r) return;
        if(r<s||e<l) return;
        if(l<=s&&e<=r){
            tree[node].push_back(edge);
            return;
        }
        ll mid=(s+e)>>1;
        update(node<<1,s,mid,l,r,edge);
        update(node<<1|1,mid+1,e,l,r,edge);
    }

    void dfs(ll node, ll s, ll e){
        vector<pll>real_connected;
        for(auto&[u,v]:tree[node]){
            auto [x,y]=dsu._union(u,v);
            if(x!=-1) real_connected.push_back({x,y});
        }
        if(s==e){
            if(get<0>(query[s])==3){ //connect?
                ans.push_back((dsu._find(get<1>(query[s]))==dsu._find(get<2>(query[s]))));
            }
        }
        else{
            ll mid = (s+e)>>1;
            dfs(node<<1, s, mid);
            dfs(node<<1|1, mid+1, e);
        }
        reverse(real_connected.begin(), real_connected.end());
        for(auto&[x,y]:real_connected) dsu._delete(x,y);
    }
};

void solve(ll testcase) {
    ll i, j;
    ll n, q; cin>>n>>q;
    vector<tlll> query(q);
    for (i=0;i<q;i++) {
        ll t, u, v;
        cin>>t>>u>>v;
        --u, --v;
        query[i] = {t, u, v};
    }
    OFDC ofdc(n, q, query);
    for (auto x: ofdc.ans) cout<<x<<endl;
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