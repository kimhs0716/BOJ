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
constexpr ll INF = 1e18;

struct UF {
    ll n;
    vl par, sz;
    UF(ll n) : n(n), par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

void preprocess() {
    ll i, j, k;
}

void sort3(ll &x, ll &y, ll &z) {
    if (x>y) swap(x, y);
    if (y>z) swap(z, y);
    if (x>y) swap(x, y);
}

void solve(ll testcase) {
    ll i, j, k;
    ll a, b, c; cin>>a>>b>>c;
    sort3(a, b, c);
    ll S = a+b+c;
    set<pll> vis;
    queue<pll> q;
    q.push({a, b});
    vis.insert({a, b});
    while (q.size()) {
        // cout<<q.size()<<endl;
        auto [x, y] = q.front(); q.pop();
        ll z = S - (x+y);
        if (x==y && y==z) {
            cout<<"1\n";
            return;
        }
        if (x!=y) {
            ll a = x<<1, b = y-x, c = z;
            sort3(a, b, c);
            if (!vis.contains({a, b})) {
                vis.insert({a, b});
                q.push({a, b});
            }
        }
        if (y!=z) {
            ll a = y<<1, b = z-y, c = x;
            sort3(a, b, c);
            if (!vis.contains({a, b})) {
                vis.insert({a, b});
                q.push({a, b});
            }
        }
        if (x!=z) {
            ll a = x<<1, b = z-x, c = y;
            sort3(a, b, c);
            if (!vis.contains({a, b})) {
                vis.insert({a, b});
                q.push({a, b});
            }
        }
    }
    cout<<"0\n";
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

