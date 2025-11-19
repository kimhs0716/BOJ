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

struct SEG {
    ll n;
    vl seg;
    SEG(ll n) : n(n), seg(n<<2) {}
    void update(ll i, ll l, ll r, ll tar, ll diff) {
        if (l==r) {
            seg[i] += diff;
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, diff);
        else update(i<<1|1, m+1, r, tar, diff);
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
    void update(ll tar, ll diff) {
        update(1, 0, n-1, tar, diff);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        if (s<=l && r<=e) return seg[i];
        if (e<l || r<s) return 0;
        ll m=l+r>>1;
        return query(i<<1, l, m, s, e) + query(i<<1|1, m+1, r, s, e);
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
    // 1-based
    ll kth(ll i, ll l, ll r, ll k) {
        if (l==r) return l;
        ll m=l+r>>1;
        ll leftsum = query(l, m);
        if (leftsum >= k) return kth(i<<1, l, m, k);
        return kth(i<<1|1, m+1, r, k-leftsum);
    }
    ll kth(ll k) {
        return kth(1, 0, n-1, k);
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    SEG seg(1'000'000);
    while (n--) {
        ll a, b, c; cin>>a>>b;
        if (a==1) {
            ll k = seg.kth(b);
            cout<<k+1<<endl;
            seg.update(k, -1);
        }
        else {
            cin>>c;
            seg.update(b-1, c);
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

