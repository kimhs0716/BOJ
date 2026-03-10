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
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

ld len(ld r, ld R, ld D) {
    if (fabsl(r-R) <= eps) return 2*D + 2*numbers::pi*R;
    if (r>R) swap(r, R);
    ld x = r*D / (R-r);
    ld theta = acosl(r/x);
    ld a = sqrtl(1 - r*r/(x*x));
    return 2*(a*D + R*(numbers::pi-theta) + r*theta);
}

ld dist(ld x, ld y) {
    return sqrtl(x*x + y*y);
}

struct UF {
    ll n;
    vl sz, par;
    UF(ll n) : n(n), sz(n, 1), par(n) {
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        return par[x] = (par[x]==x ? x : find(par[x]));
    }
    void join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x==y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vector<array<ld, 3>> arr(n);
    for (auto &[x, y, r] : arr) cin>>x>>y>>r;
    vector<tuple<ld, ll, ll>> edges;
    edges.reserve(n*n/2);
    for (i=0;i<n;i++) {
        auto [x1, y1, r1] = arr[i];
        for (j=0;j<i;j++) {
            auto [x2, y2, r2] = arr[j];
            ld D = dist(x1-x2, y1-y2);
            ld w = 0;
            if (D>r1+r2+eps)
                w = len(r1, r2, D);
            edges.push_back({w, i, j});
        }
    }
    sort(edges.begin(), edges.end());
    UF uf(n);
    ld ans = 0;
    for (auto [w, u, v] : edges) {
        // cout<<w<<' '<<u<<' '<<v<<endl;
        if (uf.same(u, v)) continue;
        ans += w;
        uf.join(u, v);
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    // cin >> testcase;
    for (ll i = 1; i     <= testcase; i++) {
        solve(i);
    }
}
