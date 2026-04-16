#include <bits/stdc++.h>

#include <utility>
#pragma GCC optimize ("O0,unroll-loops")
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

void preprocess() {
    ll i, j;
}

struct UF {
    ll n;
    vl sz, par, dist;
    UF(ll n=0) : n(n), sz(n, 1), par(n), dist(n) {
        iota(par.begin(), par.end(), 0);
    }
    ll add() {
        ll id = n++;
        sz.push_back(1);
        par.push_back(id);
        dist.push_back(0);
        return id;
    }
    pll find(ll x) {
        if (x == par[x]) return {x, 0};
        auto [r, dr] = find(par[x]);
        par[x] = r;
        // dist[x] += dr;
        dist[x] ^= dr;
        return {r, dist[x]};
    }
    bool join(ll x, ll y, ll w) {
        // dist[y] = dist[x] + w
        auto [rx, dx] = find(x);
        auto [ry, dy] = find(y);
        // if (rx == ry) return dx+w == dy;
        if (rx == ry) return dy == (dx^w);
        if (sz[rx] < sz[ry]) {
            swap(rx, ry);
            swap(dx, dy);
            // w = -w;
        }
        sz[rx] += sz[ry];
        par[ry] = rx;
        // dist[ry] = dx - dy + w;
        dist[ry] = dx ^ dy ^ w;
        return true;
    }
    bool same(ll x, ll y) {
        return find(x).first == find(y).first;
    }
    ll rel(ll x, ll y) {
        auto [rx, dx] = find(x);
        auto [ry, dy] = find(y);
        if (rx != ry) return -1;
        return (dx ^ dy);
    }
};

void solve(ll tc){
    ll i, j;
    map<string, ll> id;
    ll n, m; cin>>n>>m;
    UF uf;
    bool ok = true;
    while (n--) {
        string a, b, c; cin>>a>>b>>c;
        if (!id.contains(a)) id[a] = uf.add();
        if (!id.contains(b)) id[b] = uf.add();
        bool res;
        if (c=="parallel") res = uf.join(id[a], id[b], 0);
        else res = uf.join(id[a], id[b], 1);
        ok &= res;
    }
    if (!ok) {
        cout<<"Waterloo\n";
        return;
    }
    while (m--) {
        string a, b; cin>>a>>b;
        if (!id.contains(a) || !id.contains(b) || uf.rel(id[a], id[b])==-1) cout<<"unknown\n";
        else {
            cout<<(uf.rel(id[a], id[b]) ? "intersect" : "parallel")<<endl;
        }
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
