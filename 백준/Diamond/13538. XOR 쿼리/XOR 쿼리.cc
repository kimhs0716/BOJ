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
    ll val, root_idx;
    Node() {
        l = r = nullptr;
        val = 0;
        root_idx = 0;
    }
    ~Node() {
        if (l && l->root_idx==root_idx) delete l;
        if (r && r->root_idx==root_idx) delete r;
    }
};

Node *roots[1<<19|5];
struct PST {
    vl arr;
    ll n, sz;
    PST(ll n) : n(n), arr(n), sz(0) {
        roots[sz++] = new Node;
        init(roots[0], 0, n-1);
    }
    PST(vl &a) : n(a.size()), arr(a), sz(0) {
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
    void update(ll tar, ll val) {
        Node *x = roots[sz-1];
        Node *y = new Node;
        roots[sz++] = y;
        ll ri = sz-1;
        y->root_idx = ri;
        ll l=0, r=n-1;
        vector<Node*> st;
        while (l<r) {
            st.push_back(y);
            ll m = (l+r)>>1;
            if (tar<=m) {
                y->r = x->r;
                y->l = new Node;
                y->root_idx = ri;
                y = y->l;
                x = x->l;
                r = m;
            }
            else {
                y->l = x->l;
                y->r = new Node;
                y->root_idx = ri;
                y = y->r;
                x = x->r;
                l = m+1;
            }
        }
        y->val = x->val + val;
        while (st.size()) {
            y = st.back(); st.pop_back();
            y->val = y->l->val + y->r->val;
        }
    }
    void del() {
        delete roots[--sz];
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
    ll xor_query(Node *x, Node *y, ll l, ll r, ll k) {
        ll level = 18;
        ll ret = 0;
        while (l<r) {
            ret <<= 1;
            ll t = (k>>level)&1;
            ll m = (l+r)>>1;
            bool left = 0;
            if (t==1) {
                if (y->l->val - x->l->val)
                    left = 1;
            }
            else {
                if (y->r->val - x->r->val == 0)
                    left = 1;
            }
            if (left) {
                x = x->l;
                y = y->l;
                r = m;
            }
            else {
                x = x->r;
                y = y->r ;
                l = m+1;
                ret |= 1;
            }
            level--;
        }
        return ret;
    }
    ll xor_query(ll i, ll j, ll k) {
        return xor_query(roots[i-1], roots[j], 0, n-1, k);
    }
};

void solve(ll tc){
    ll i, j;
    PST pst(1<<19);
    ll q; cin>>q;
    while (q--) {
        ll a, b, c, d; cin>>a>>b;
        if (a==1) {
            pst.update(b, 1);
        }
        else if (a==2) {
            cin>>c>>d;
            cout<<pst.xor_query(b, c, d)<<endl;
        }
        else if (a==3) {
            while (b--) {
                pst.del();
            }
        }
        else if (a==4) {
            cin>>c>>d;
            cout<<pst.query(c, 0, d) - pst.query(b-1, 0, d)<<endl;
        }
        else if (a==5) {
            cin>>c>>d;
            cout<<pst.kth(b, c, d)<<endl;
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
