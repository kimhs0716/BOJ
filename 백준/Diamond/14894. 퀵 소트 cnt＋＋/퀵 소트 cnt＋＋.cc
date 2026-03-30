#include <bits/stdc++.h>

#include <utility>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
// using ll = long long;
using ll = int;
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

// constexpr ll MOD = 1e9+7;
// // constexpr ll MOD = 998'244'353;
// constexpr ll INF = 1e18;
// constexpr ll MAX = 500'000;
// constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

struct Node {
    ll val;
    // ll idx;
    Node *l, *r;
    Node() {
        val = 0;
        // idx = 0;
        l = r = nullptr;
    }
    // ~Node() {
    //     if (l && l->idx == idx) delete l;
    //     if (r && r->idx == idx) delete r;
    // }
};

struct PST {
    ll n;
    vector<Node*> roots, st;
    PST(ll n) : n(n) {
        roots.push_back(new Node());
        init(roots.back(), 0, n-1);
    }
    // ~PST() {
    //     while (roots.size()) {
    //         delete roots.back();
    //         roots.pop_back();
    //     }
    // }
    void init(Node *x, ll l, ll r) {
        if (l==r) return;
        ll m = (l+r)>>1;
        x->l = new Node();
        init(x->l, l, m);
        x->r = new Node();
        init(x->r, m+1, r);
    }
    void update(Node *x, ll tar, ll diff) {
        ll idx = roots.size();
        Node *y = new Node();
        // y->idx = idx;
        roots.push_back(y);
        ll l=0, r=n-1;
        while (l<r) {
            st.push_back(y);
            ll m = (l+r)>>1;
            if (tar<=m) {
                y->l = new Node();
                // y->l->idx = idx;
                y->r = x->r;
                y = y->l;
                x = x->l;
                r = m;
            }
            else {
                y->r = new Node();
                // y->r->idx = idx;
                y->l = x->l;
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
    void update(ll pr, ll tar, ll diff) {
        update(roots[pr], tar, diff);
    }
    void update(ll tar, ll diff) {
        update(roots.back(), tar, diff);
    }
    ll query(Node *x, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return x->val;
        ll m = (l+r)>>1;
        return query(x->l, l, m, s, e) + query(x->r, m+1, r, s, e);
    }
    ll query(ll i, ll s, ll e) {
        return query(roots[i], 0, n-1, s, e);
    }
    ll kth(Node *x, Node *y, ll k) {
        ll l=0, r=n-1;
        while (l<r) {
            ll m = (l+r)>>1;
            ll diff = y->l->val - x->l->val;
            if (diff>=k) {
                x = x->l;
                y = y->l;
                r = m;
            }
            else {
                x = x->r;
                y = y->r;
                l = m+1;
                k -= diff;
            }
        }
        return l;
    }
    ll kth(ll i, ll j, ll k) {
        return kth(roots[i-1], roots[j], k);
    }
};

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vl pos(n+1), arr(n);
    for (i=1;i<=n;i++) {
        ll x; cin>>x;
        pos[x] = i;
        arr[i-1] = x;
    }
    // cout<<pos<<endl;
    PST pst(n+1);
    for (i=1;i<=n;i++) {
        pst.update(pos[i], 1);
    }
    long long ans = 0;
    vp st;
    st.push_back({1, n});
    while (st.size()) {
        auto [lo, hi] = st.back();
        st.pop_back();
        ll len = hi-lo+1;
        if (len<=1) continue;
        ans += len;
        ll pivot = arr[pst.kth(lo, hi, (len+1)/2)-1];
        st.push_back({lo, pivot-1});
        st.push_back({pivot+1, hi});
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
