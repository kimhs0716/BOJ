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
    vl par, sz;
    UF(ll n) : n(n), par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x==y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n, m; cin>>n>>m;
    vector<tlll> edges(m);
    for (auto &[w, u, v] : edges) {
        cin>>u>>v>>w;
        --u; --v;
    }
    ll s, e; cin>>s>>e;
    --s; --e;
    sort(edges.rbegin(), edges.rend());
    function<bool(ll)> check = [&edges, s, e, n](ll k) {
        UF uf(n);
        for (auto [w, u, v] : edges) {
            if (w<k) break;
            uf.join(u, v);
        }
        return uf.same(s, e);
    };
    ll lo=0, hi=edges[0][0]+1;
    while (lo+1<hi) {
        ll mid=(lo+hi)>>1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout<<lo<<endl;
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

