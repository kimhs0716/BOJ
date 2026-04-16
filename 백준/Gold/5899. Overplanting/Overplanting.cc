#include <bits/stdc++.h>
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

constexpr ll S = -1e8;
constexpr ll E = 1e8-1;

struct Node {
    ll cover, len;
    Node *l, *r;
    Node() {
        cover = len = 0;
        l = r = nullptr;
    }
    ~Node() {
        delete l;
        delete r;
    }
} *root;

void update(Node *cur, ll l, ll r, ll s, ll e, ll v) {
    if (r<s || e<l) return;
    if (s<=l && r<=e) {
        cur->cover += v;
    }
    else {
        ll m = l+r>>1;
        if (s<=m) {
            if (!cur->l) cur->l = new Node;
            update(cur->l, l, m, s, e, v);
        }
        if (m+1<=e) {
            if (!cur->r) cur->r = new Node;
            update(cur->r, m+1, r, s, e, v);
        }
    }
    if (cur->cover) {
        cur->len = r-l+1;
    }
    else {
        if (l==r) cur->len = 0;
        else {
            cur->len = (cur->l ? cur->l->len : 0);
            cur->len += (cur->r ? cur->r->len : 0);
        }
    }
}

void update(ll s, ll e, ll v) {
    update(root, S, E, s, e, v);
}

ll query(Node *cur, ll l, ll r, ll s, ll e) {
    if (r<s || e<l) return 0;
    if (!cur) return 0;
    if (s<=l && r<=e) return cur->len;
    ll m=l+r>>1;
    return query(cur->l, l, m, s, e) + query(cur->r, m+1, r, s, e);
}

ll query(ll s, ll e) {
    return query(root, S, E, s, e);
}

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    root = new Node;
    ll n; cin>>n;
    ll ans = 0;
    map<ll, pair<vp, vp>> queries;
    while (n--) {
        ll a, b, c, d; cin>>a>>b>>c>>d;
        queries[a].first.push_back({d, b});
        queries[c].second.push_back({d, b});
    }
    ll prev_x = queries.begin()->first;
    for (auto &[x, p] : queries) {
        auto &[in, out] = p;
        ans += (x-prev_x) * query(S, E);
        // cout<<x-prev_x<<' '<<query(S, E)<<endl;
        for (auto [y1, y2] : in) update(y1, y2-1, 1);
        for (auto [y1, y2] : out) update(y1, y2-1, -1);
        prev_x = x;
    }
    cout<<ans<<endl;
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

