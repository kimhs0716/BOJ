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
    void update(ll i, ll l, ll r, Line v) {
        if (l==r) {
            if (tree[i].line.get(l) < v.get(l))
                tree[i].line = v;
            return;
        }
        ll m = (l+r)>>1;
        Line lo = tree[i].line, hi = v;
        if (lo.get(l) > hi.get(l)) swap(lo, hi);
        if (lo.get(r) < hi.get(r)) {
            tree[i].line = hi;
            return;
        }
        if (lo.get(m) < hi.get(m)) {
            tree[i].line = hi;
            if (tree[i].r == -1) {
                tree[i].r = tree.size();
                tree.push_back({-1, -1, {0, -INF}});
            }
            update(tree[i].r, m+1, r, lo);
        }
        else {
            tree[i].line = lo;
            if (tree[i].l == -1) {
                tree[i].l = tree.size();
                tree.push_back({-1, -1, {0, -INF}});
            }
            update(tree[i].l, l, m, hi);
        }
    }
    void update(ll a, ll b) {
        update(0, s, e, {a, b});
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

void solve(ll tc){
    ll i, j;
    ll MAX = 1'000'000'000'000;
    Li_Chao tree(-MAX, MAX);
    ll n; cin>>n;
    while (n--) {
        ll a, b, c; cin>>a>>b;
        if (a==1) {
            cin>>c;
            tree.update(b, c);
        }
        else {
            cout<<tree.query(b)<<endl;
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
