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

struct Node {
    Node *l, *r;
    ll val;
    Node() {
        l = r = nullptr;
        val = 0;
    }
};

struct PST {
    vl arr;
    ll n, sz;
    Node *roots[100005];
    PST(vl a) : arr(a), n(a.size()), sz(0) {
        roots[sz++] = new Node;
        init(roots[0], 0, n-1);
    }
    void init(Node *x, ll l, ll r) {
        if (l==r) {
            x->val = arr[l];
            return;
        }
        ll m = (l+r)>>1;
        if (!x->l) x->l = new Node;
        if (!x->r) x->r = new Node;
        init(x->l, l, m);
        init(x->r, m+1, r);
        x->val = x->l->val + x->r->val;
    }
    void update(ll tar, ll diff) {
        Node *x = roots[sz-1];
        Node *y = new Node;
        roots[sz++] = y;
        ll l=0, r=n-1;
        vector<Node*> st;
        while (l<r) {
            st.push_back(y);
            ll m = (l+r)>>1;
            if (tar<=m) {
                y->r = x->r;
                y->l = new Node;
                y = y->l;
                x = x->l;
                r = m;
            }
            else {
                y->l = x->l;
                y->r = new Node;
                y = y->r;
                x = x->r;
                l = m+1;
            }
        }
        y->val = x->val + diff;
        while (st.size()) {
            y = st.back(); st.pop_back();
            y->val = y->l->val + y->r->val;
        }
    }
    ll query(Node *x, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return x->val;
        ll m = (l+r)>>1;
        return query(x->l, l, m, s, e) + query(x->r, m+1, r, s, e);
    }
    ll query(ll k, ll s, ll e) {
        return query(roots[k], 0, n-1, s, e);
    }
    ll kth(Node *x, Node *y, ll l, ll r, ll k) {
        if (l==r) return l;
        ll m = (l+r)>>1;
        ll diff = y->l->val - x->l->val;
        if (diff >= k) return kth(x->l, y->l, l, m, k);
        return kth(x->r, y->r, m+1, r, k-diff);
    }
    ll kth(ll i, ll j, ll k) {
        return kth(roots[i-1], roots[j], 0, n-1, k);
    }
};

void solve(ll tc){
    ll i, j;
    ll n, q; cin>>n>>q;
    vp arr(n);
    for (i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    unordered_map<ll, ll> num2id, id2num;
    for (auto &[x, i]: arr) {
        if (num2id.count(x)==0) {
            ll id = num2id.size();
            num2id[x] = id;
            id2num[id] = x;
        }
        x = num2id[x];
    }
    sort(arr.begin(), arr.end(), [](const pll &a, const pll &b) {
        return a.second < b.second;
    });
    // for (auto &[x, i]: arr) cout<<x<<' '; cout<<endl;
    PST pst(vl(num2id.size()));
    for (auto [x, i] : arr) pst.update(x, 1);
    while (q--) {
        ll k; cin>>i>>j>>k;
        cout<<id2num[pst.kth(i, j, k)]<<endl;
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
