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
constexpr ll MAX = 500'000;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

struct UF {
    ll n;
    vl sz, par;
    vp st;
    UF(ll n) : n(n), sz(n, 1), par(n) {
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        if (x==par[x]) return x;
        return find(par[x]);
    }
    bool join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x==y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        st.push_back({x, y});
        return true;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
    void rollback() {
        auto [x, y] = st.back(); st.pop_back();
        par[y] = y;
        sz[x] -= sz[y];
    }
};

struct OFDC {
    ll n, q;
    vector<tlll> query;
    vvp seg;
    UF uf;
    vl ans;
    OFDC(ll n, vector<tlll> &qq) : n(n), q(qq.size()), query(qq), seg(q<<2), uf(n) {
        map<pll, ll> in;
        for (ll i=0;i<q;i++) {
            auto [t, u, v] = qq[i];
            if (t==1) {
                in[{u, v}] = i;
            }
            else if (t==2) {
                ll s = in[{u, v}];
                update(1, 0, q-1, s, i, u, v);
                in.erase({u, v});
            }
        }
        for (auto [edge, s] : in) {
            auto [u, v] = edge;
            update(1, 0, q-1, s, q-1, u, v);
        }
        dfs(1, 0, q-1);
    }
    void update(ll i, ll l, ll r, ll s, ll e, ll u, ll v) {
        if (r<s || e<l) return;
        if (s<=l && r<=e) {
            seg[i].push_back({u, v});
            return;
        }
        ll m = (l+r)>>1;
        update(i<<1, l, m, s, e, u, v);
        update(i<<1|1, m+1, r, s, e, u, v);
    }
    void dfs(ll i, ll l, ll r) {
        ll cnt = 0;
        for (auto [u, v] : seg[i]) {
            if (uf.join(u, v)) cnt++;
        }
        if (l==r) {
            auto [t, u, v] = query[l];
            if (t==3) ans.push_back(uf.same(u, v));
        }
        else {
            ll m = (l+r)>>1;
            dfs(i<<1, l, m);
            dfs(i<<1|1, m+1, r);
        }
        while (cnt--) uf.rollback();
    }
};

void solve(ll tc){
    int i, j;
    ll n, m; cin>>n>>m;
    vector<tlll> query(m);
    for (auto &[t, u, v] : query) {
        cin>>t>>u>>v;
        if (u>v) swap(u, v);
    }
    OFDC ofdc(n+1, query);
    for (auto x : ofdc.ans) cout<<x<<endl;
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
