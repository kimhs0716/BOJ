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
constexpr ll MAX = 500'000;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

struct UF {
    ll n;
    vl rank, par, dist;
    vector<array<ll, 4>> st;
    bool has_contradiction;
    UF(ll n) : n(n), rank(n, 0), par(n), dist(n) {
        iota(par.begin(), par.end(), 0);
        has_contradiction = false;
    }
    pll find(ll x) {
        ll d = 0;
        while (par[x] != x) {
            d += dist[x];
            x = par[x];
        }
        return {x, d};
    }
    void join(ll x, ll y, ll w) {
        auto [px, dx] = find(x);
        auto [py, dy] = find(y);
        ll prev = has_contradiction;
        if (px == py) {
            st.push_back({0, prev, 0, 0});
            if (dy - dx != w) has_contradiction = true;
            return;
        }
        if (rank[px] < rank[py]) {
            par[px] = py;
            dist[px] = dy - dx - w;
            st.push_back({1, px, 0, prev});
            return;
        }
        par[py] = px;
        dist[py] = dx - dy + w;
        ll inc = 0;
        if (rank[px] == rank[py]) {
            rank[px]++;
            inc = 1;
        }
        st.push_back({1, py, inc, prev});
    }
    void rollback() {
        auto [t, a, b, c] = st.back();
        st.pop_back();
        if (t == 0) {
            has_contradiction = a;
            return;
        }
        if (b) rank[par[a]]--;
        par[a] = a;
        dist[a] = 0;
        has_contradiction = c;
    }
};

struct OFDC {
    ll n, k, q;
    vp query;
    vector<tlll> edges;
    vvl seg;
    UF uf;
    vl ans;
    OFDC(ll n, ll k) : n(n), uf(k), edges(n) {
        query.reserve(n<<2);
    }
    void build() {
        q = query.size();
        seg.resize(q<<2);
        vl in(n);
        for (ll i=0;i<q;i++) {
            auto [t, idx] = query[i];
            if (t==1) {
                auto [u, v, w] = edges[idx];
                in[idx] = i;
            }
            else if (t==2) {
                auto [u, v, w] = edges[idx];
                update(1, 0, q-1, in[idx], i, idx);
                in[idx] = -1;
            }
        }
        for (ll i=0;i<n;i++) {
            if (in[i] == -1) continue;
            auto [u, v, w] = edges[i];
            update(1, 0, q-1, in[i], q-1, i);
        }
        dfs(1, 0, q-1);
    }
    void update(ll i, ll l, ll r, ll s, ll e, ll idx) {
        if (r<s || e<l) return;
        if (s<=l && r<=e) {
            seg[i].push_back(idx);
            return;
        }
        ll m = (l+r)>>1;
        update(i<<1, l, m, s, e, idx);
        update(i<<1|1, m+1, r, s, e, idx);
    }
    void dfs(ll i, ll l, ll r) {
        for (ll idx : seg[i]) {
            auto [u, v, w] = edges[idx];
            uf.join(u, v, w);
        }
        if (l==r) {
            ll t = query[l].first;
            if (t==3) ans.push_back(uf.has_contradiction);
        }
        else {
            ll m = (l+r)>>1;
            dfs(i<<1, l, m);
            dfs(i<<1|1, m+1, r);
        }
        for (auto &x : seg[i])
            uf.rollback();
    }
};

void solve(ll tc){
    ll i, j;
    ll n, k; cin>>n>>k;
    OFDC ofdc(n, k);
    for (i=0;i<n;i++) {
        ll u, v, w; cin>>u>>v>>w;
        --u; --v;
        if (u>v) {
            swap(u, v);
            w = -w;
        }
        ofdc.query.push_back({1, i});
        ofdc.edges[i] = {u, v, w};
    }
    for (i=0;i<n;i++) {
        ofdc.query.push_back({2, i});
        ofdc.query.push_back({3, -1});
        ofdc.query.push_back({1, i});
    }
    ofdc.build();
    for (i=0;i<n;i++) {
        if (ofdc.ans[i]==0) {
            cout<<i+1<<endl;
            return;
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
