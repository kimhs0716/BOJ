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

struct Line {
    ll a, b;
    ll get(ll x) {
        return a*x + b;
    }
};

struct Node {
    ll l, r; // child
    Line line;
};

struct Li_Chao {
    ll s, e;
    vector<Node> tree;
    Li_Chao(ll s, ll e) : s(s), e(e) {
        tree.push_back({-1, -1, {0, -INF}});
    }
    vl hist;
    vector<pair<ll, Line>> st;
    void update(ll i, ll l, ll r, Line v) {
        if (l==r) {
            if (tree[i].line.get(l) < v.get(l)) {
                st.push_back({i, tree[i].line});
                tree[i].line = v;
            }
            return;
        }
        ll m = (l+r)>>1;
        Line lo = tree[i].line, hi = v;
        if (lo.get(l) > hi.get(l)) swap(lo, hi);
        if (lo.get(r) < hi.get(r)) {
            st.push_back({i, tree[i].line});
            tree[i].line = hi;
            return;
        }
        if (lo.get(m) < hi.get(m)) {
            st.push_back({i, tree[i].line});
            tree[i].line = hi;
            if (tree[i].r == -1) {
                tree[i].r = tree.size();
                tree.push_back({-1, -1, {0, -INF}});
            }
            update(tree[i].r, m+1, r, lo);
        }
        else {
            st.push_back({i, tree[i].line});
            tree[i].line = lo;
            if (tree[i].l == -1) {
                tree[i].l = tree.size();
                tree.push_back({-1, -1, {0, -INF}});
            }
            update(tree[i].l, l, m, hi);
        }
    }
    void update(ll a, ll b) {
        hist.push_back(st.size());
        update(0, s, e, {a, b});
    }
    void rollback() {
        ll sz = hist.back();
        hist.pop_back();
        while (st.size() > sz) {
            auto [i, l] = st.back();
            st.pop_back();
            tree[i].line = l;
        }
    }
    ll query(ll i, ll l, ll r, ll x) {
        if (i==-1) return -INF;
        ll m = (l+r)>>1;
        if (x<=m) return max(tree[i].line.get(x), query(tree[i].l, l, m, x));
        else return max(tree[i].line.get(x), query(tree[i].r, m+1, r, x));
    }
    ll query(ll t) {
        return query(0, s, e, t);
    }
};

struct OFDC {
    ll S, E, q;
    vl ans;
    vvp seg;
    Li_Chao tree;
    vector<tlll> query;
    OFDC(ll s, ll e, vector<tlll> &qq) : S(s), E(e), q(qq.size()), query(qq), seg(q<<2), tree(S, E) {
        vp temp(q);
        for (ll i=0;i<q;i++) {
            auto [t, x, y] = query[i];
            if (t==2) {
                auto [tt, a, b] = query[x-1];
                update(1, 0, q-1, x-1, i, a, b);
                query[x-1] = {-1, -1, -1};
            }
        }
        for (ll i=0;i<q;i++) {
            auto [t, a, b] = query[i];
            if (t==1) update(1, 0, q-1, i, q-1, a, b);
        }
        dfs(1, 0, q-1);
    }
    void update(ll i, ll l, ll r, ll s, ll e, ll a, ll b) {
        if (r<s || e<l) return;
        if (s<=l && r<=e) {
            seg[i].push_back({a, b});
            return;
        }
        ll m = (l+r)>>1;
        update(i<<1, l, m, s, e, a, b);
        update(i<<1|1, m+1, r, s, e, a, b);
    }
    void dfs(ll i, ll l, ll r) {
        for (auto [a, b] : seg[i]) {
            tree.update(a, b);
        }
        if (l==r) {
            auto [t, a, b] = query[l];
            if (t==3) {
                ans.push_back(tree.query(a));
            }
        }
        else {
            ll m = (l+r)>>1;
            dfs(i<<1, l, m);
            dfs(i<<1|1, m+1, r);
        }
        for (auto &[a, b] : seg[i]) {
            tree.rollback();
        }
    }
};

void solve(ll tc){
    ll i, j;
    ll MAX = 1'000'000'000;
    ll q; cin>>q;
    vector<tlll> query(q);
    for (auto &[t, x, y] : query) {
        cin>>t;
        if (t==1) {
            cin>>x>>y;
        }
        else {
            cin>>x;
            y = 0;
        }
    }
    OFDC ofdc(-MAX, MAX, query);
    for (auto x : ofdc.ans) {
        if (x == -INF) {
            cout<<"EMPTY\n";
        }
        else cout<<x<<endl;
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
