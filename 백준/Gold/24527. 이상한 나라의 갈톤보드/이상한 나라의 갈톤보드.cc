#include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;

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
ostream& operator<<(ostream &os, vector<T> &arr) {
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

// usage: LAZY(n, arr); update(qs, qe, val); ll sum = query(qs, qe);
// memo : 0-indexed
struct LAZY {
    ll n;
    vector<ld> seg, lazy, arr;

    LAZY(ll n, vector<ld>& arr): n(n),arr(arr),seg(n<<2),lazy(n<<2){
        init(1,0,n-1);
    }

    void init(ll node,ll l,ll r) {
        if (l==r) {
            seg[node]=arr[l];
            return;
        }
        ll m=(l+r)>>1;
        init(node<<1,l,m);
        init(node<<1|1,m+1,r);
        seg[node]=seg[node<<1]+seg[node<<1|1];
    }

    void relax(ll node, ll l, ll r) {
        if (lazy[node]==0) return;
        if (l<r) {
            ll m = (l+r)>>1;
            seg[node<<1]+=(m-l+1)*lazy[node];
            lazy[node<<1]+=lazy[node];
            seg[node<<1|1]+=(r-m)*lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }

    ld range_sum(ll node, ll l, ll r, ll s, ll e) {
        if (r<s||e<l) return 0;
        if (s<=l&&r<=e) return seg[node];
        relax(node,l,r);
        ll m=(l+r)>>1;
        return range_sum(node<<1,l,m,s,e) + range_sum(node<<1|1,m+1,r,s,e);
    }

    void range_update(ll node, ll l, ll r, ll s, ll e, ld val) {
        if (r<s||e<l) return;
        if (s<=l&&r<=e) {
            seg[node]+=(r-l+1)*val;
            lazy[node]+=val;
            return;
        }
        relax(node,l,r);
        ll m=(l+r)>>1;
        range_update(node<<1,l,m,s,e,val);
        range_update(node<<1|1,m+1,r,s,e,val);
        seg[node]=seg[node<<1]+seg[node<<1|1];
    }
    void update(ll s,ll e,ld val){range_update(1,0,n-1,s,e,val);}
    ld query(ll s,ll e){return range_sum(1,0,n-1,s,e);}
};

ll find_i(ll a) {
    ll lo = 0, hi = 100000;
    while (lo < hi) {
        ll mid = (lo + hi + 1) >> 1;
        ll T =mid * (mid + 1) / 2;
        if (T < a) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

void solve(ll testcase) {
    ll i, j;
    ll h, q, r; cin>>h>>q>>r;
    vector<ld> arr(h+1);
    LAZY segtree(h+1, arr);
    while (q--) {
        ll a, b; cin>>a>>b;
        i = find_i(a);
        a -= i*(i+1)/2;
        // cout<<a<<' '<<i<<' '<<endl;
        // cout<<a<<' '<<a+h-i<<endl;
        segtree.update(a-1, a+h-i-1, (ld)b / (h-i+1));
    }
    while (r--) {
        ll a, b; cin>>a>>b;
        cout<<segtree.query(a-1, b-1)<<endl;
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