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
constexpr ll INF = 1e18;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

struct UF {
    ll n;
    vl par, sz;
    UF(ll n) : n(n), par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        return x==par[x] ? x : (par[x]=find(par[x]));
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

void solve(ll tc){
    ll i, j;
    ll n, m, q; cin>>n>>m>>q;
    vector<tlll> edges(m);
    for (auto &[w, u, v] : edges) {
        cin>>u>>v>>w;
        --u; --v;
    }
    sort(edges.rbegin(), edges.rend());
    UF uf(n);
    vl ans(q);
    vp query(q);
    for (auto &[u, v] : query) {
        cin>>u>>v;
        --u; --v;
    }
    ll cnt = 0;
    for (i=0;i<m;i++) {
        auto [w, u, v] = edges[i];
        uf.join(u, v);
        for (j=0;j<q;j++) {
            auto [u, v] = query[j];
            if (ans[j]==0 && uf.same(u, v)) {
                ans[j] = w;
                cnt++;
            }
        }
        if (cnt==q) break;
    }
    for (auto x : ans) cout<<x<<endl;
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
