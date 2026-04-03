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

struct SEG {
    ll n;
    vl seg, lazy;
    SEG(vl &arr) : n(arr.size()), seg(n<<2), lazy(n<<2) {
        init(1, 0, n-1, arr);
    }
    void init(ll i, ll l, ll r, const vl &arr) {
        if (l==r) {
            seg[i] = arr[l];
            return;
        }
        ll m = (l+r)>>1;
        init(i<<1, l, m, arr);
        init(i<<1|1, m+1, r, arr);
        seg[i] = seg[i<<1] ^ seg[i<<1|1];
    }
    void push(ll i, ll l, ll r) {
        if (!lazy[i]) return;
        ll len = r-l+1;
        seg[i] ^= (len&1) * lazy[i];
        if (l<r) {
            lazy[i<<1] ^= lazy[i];
            lazy[i<<1|1] ^= lazy[i];
        }
        lazy[i] = 0;
    }
    void update(ll i, ll l, ll r, ll s, ll e, ll diff) {
        push(i, l, r);
        if (r<s || e<l) return;
        if (s<=l && r<=e) {
            lazy[i] ^= diff;
            push(i, l, r);
            return;
        }
        ll m = (l+r)>>1;
        update(i<<1, l, m, s, e, diff);
        update(i<<1|1, m+1, r, s, e, diff);
        seg[i] = seg[i<<1] ^ seg[i<<1|1];
    }
    void update(ll s, ll e, ll diff) {
        update(1, 0, n-1, s, e, diff);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        push(i, l, r);
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return seg[i];
        ll m = (l+r)>>1;
        return query(i<<1, l, m, s, e) ^ query(i<<1|1, m+1, r, s, e);
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
};

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    SEG seg(arr);
    ll q; cin>>q;
    while (q--) {
        ll a, b, c, d; cin>>a>>b>>c;
        if (a==1) {
            cin>>d;
            seg.update(b, c, d);
        }
        else {
            cout<<seg.query(b, c)<<endl;
        }
        // for (i=0;i<n;i++) cout<<seg.query(i, i)<<' '; cout<<endl;
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
