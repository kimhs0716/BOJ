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
    vl sz, grp;
    UF(ll n) : n(n), sz(n, 1), grp(n) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll find(ll x) {
        if (x==grp[x]) return x;
        return grp[x] = find(grp[x]);
    }
    bool join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x==y) return false;
        if (sz[x]<sz[y]) swap(x, y);
        sz[x] += sz[y];
        grp[y] = x;
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
    ll n, m, k; cin>>n>>m>>k;
    set<pll> broken;
    vector<tlll> edges;
    vl a(n); cin>>a;
    for (i=0;i<m;i++) {
        ll a, b; cin>>a>>b;
        if (a>b) swap(a, b);
        broken.insert({a, b});
    }
    for (i=1;i<n;i++) {
        if (broken.contains({i, i+1})) continue;
        edges.push_back({0, i, i+1});
    }
    if (!broken.contains({1, n})) {
        edges.push_back({0, 1, n});
    }
    for (i=0;i<n;i++) {
        edges.push_back({a[i], 0, i+1});
    }
    sort(edges.begin(), edges.end());
    UF uf(n+1);
    ll ans = 0;
    for (auto [w, u, v] : edges) {
        if (uf.join(u, v))
            ans += w;
    }
    if (m<=1) ans = 0;
    cout<<(ans<=k ? "YES" : "NO")<<endl;
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

