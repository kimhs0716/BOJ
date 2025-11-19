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

struct Node {
    ll data;
    Node *l, *r;
    Node() {
        data = 0;
        l = r = nullptr;
    }
    ~Node() {
        delete l;
        delete r;
    }
};

struct SEG {
    ll S, E;
    Node *root;
    SEG(ll s, ll e) : S(s), E(e) {
        root = new Node;
    }
    void update(Node *cur, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            cur->data += val;
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) {
            if (!cur->l) cur->l = new Node;
            update(cur->l, l, m, tar, val);
        }
        else {
            if (!cur->r) cur->r = new Node;
            update(cur->r, m+1, r, tar, val);
        }
        ll lv = cur->l ? cur->l->data : 0;
        ll rv = cur->r ? cur->r->data : 0;
        cur->data = lv + rv;
    }
    void update(ll tar, ll val) {
        update(root, S, E, tar, val);
    }
    ll query(Node *cur, ll l, ll r, ll s, ll e) {
        if (!cur) return 0;
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return cur->data;
        ll m=l+r>>1;
        return query(cur->l, l, m, s, e) + query(cur->r, m+1, r, s, e);
    }
    ll query(ll s, ll e) {
        return query(root, S, E, s, e);
    }
    ll kth(Node *cur, ll l, ll r, ll k) {
        if (l==r) return l;
        ll m=l+r>>1;
        ll left_sum = cur->l ? cur->l->data : 0;
        ll right_sum = cur->r ? cur->r->data : 0;
        assert(k<=left_sum+right_sum);
        if (left_sum>=k) return kth(cur->l, l, m, k);
        else return kth(cur->r, m+1, r, k-left_sum);
    }
    ll kth(ll k) {
        return kth(root, S, E, k);
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    ll n, q; cin>>n>>q;
    SEG seg(0, 1e18);
    vl arr(n); cin>>arr;
    for (i=0;i<n;i++) {
        seg.update(arr[i], 1);
    }
    while (q--) {
        ll a, b, c; cin>>a>>b;
        if (a!=4) cin>>c;
        if (a==1) {
            ll t = arr[b-1];
            arr[b-1] = t+c;
            seg.update(t, -1);
            seg.update(t+c, 1);
        }
        else if (a==2) {
            ll t = arr[b-1];
            arr[b-1] = t-c;
            seg.update(t, -1);
            seg.update(t-c, 1);
        }
        else if (a==3) {
            cout<<seg.query(b, c)<<endl;
        }
        else {
            // cout<<"TBI"<<endl;
            cout<<seg.kth(n-b+1)<<endl;
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

