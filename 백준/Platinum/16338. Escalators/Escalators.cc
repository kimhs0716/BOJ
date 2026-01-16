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
constexpr ll INF = 1e15;

struct UF {
    ll n;
    vl sz, par;
    UF(ll n) : n(n), sz(n, 1), par(n) {
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        if (x==par[x]) return x;
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
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vl t(n); cin>>t;
    vp edges;
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        edges.push_back({u, v});
    }
    ll ans = 0;
    for (i=19;i>=0;i--) {
        UF uf(n);
        for (auto [u, v] : edges) {
            if (((t[u]>>i)&(t[v]>>i))&1) {
                uf.join(u, v);
            }
        }
        ans <<= 1;
        for (j=0;j<n;j++) {
            if (uf.find(j)==j) {
                ll x = uf.sz[j];
                ans += x*(x-1)/2;
            }
        }
    }
    cout<<ans+accumulate(t.begin(), t.end(), 0LL)<<endl;
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
