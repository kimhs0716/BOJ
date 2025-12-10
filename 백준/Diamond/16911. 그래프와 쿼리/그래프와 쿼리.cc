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
    vl par, rank;
    vector<tlll> st;
    UF(ll n) : n(n), par(n), rank(n) {
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
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
            st.push_back({x, y, 1});
        }
        else {
            st.push_back({x, y, 0});
        }
        return true;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
    void rollback() {
        auto [x, y, z] = st.back();
        st.pop_back();
        par[y] = y;
        if (z) rank[x]--;
    }
};

struct OFDC {
    ll n, q;
    vector<tlll> query;
    vector<vector<pll>> seg;
    UF uf;
    vl ans;
    OFDC(ll n, vector<tlll> &qq) : n(n), q(qq.size()), query(qq), uf(n), seg((q+1)<<2) {
        map<pll, ll> in;
        for (ll i=0;i<q;i++) {
            auto [a, b, c] = query[i];
            if (b>c) swap(b, c);
            if (a==1) {
                in[{b, c}] = i;
            }
            else if (a==2) {
                ll s = in[{b, c}];
                ll e = i;
                update(1, 0, q, s, e, b, c);
                in.erase({b, c});
            }
        }
        for (auto [e, t] : in) {
            auto [b, c] = e;
            update(1, 0, q, t, q, b, c);
        }
        dfs(1, 0, q);
    }
    void update(ll i, ll l, ll r, ll s, ll e, ll x, ll y) {
        if (s<=l && r<=e) {
            seg[i].push_back({x, y});
            return;
        }
        ll m=(l+r)>>1;
        if (s<=m) update(i<<1, l, m, s, e, x, y);
        if (m+1<=e) update(i<<1|1, m+1, r, s, e, x, y);
    }
    void dfs(ll i, ll l, ll r) {
        ll cnt = 0;
        for (auto [x, y] : seg[i]) {
            cnt += uf.join(x, y);
        }
        if (l==r) {
            if (l!=q) {
                auto [a, b, c] = query[l];
                if (a==3) {
                    ans.push_back(uf.same(b, c));
                }
            }
        }
        else {
            ll m=l+r>>1;
            dfs(i<<1, l, m);
            dfs(i<<1|1, m+1, r);
        }
        while (cnt--)
            uf.rollback();
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n, m; cin>>n>>m;
    vector<tlll> q(m);
    for (auto &[x, y, z] : q) {
        cin>>x>>y>>z;
        --y; --z;
    }
    OFDC ofdc(n, q);
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

