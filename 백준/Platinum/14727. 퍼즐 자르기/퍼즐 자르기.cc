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
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

struct SEG {
    ll n;
    vl seg, arr;
    SEG(vl &arr) : n(arr.size()), arr(arr), seg(n<<2) {
        init(1, 0, n-1);
    }
    void init(ll node, ll l, ll r) {
        if (l==r) {
            seg[node] = l;
            return;
        }
        ll m = (l+r)>>1;
        init(node<<1, l, m);
        init(node<<1|1, m+1, r);
        ll left = seg[node<<1], right = seg[node<<1|1];
        if (arr[left]<arr[right]) seg[node] = left;
        else seg[node] = right;
    }
    ll query(ll node, ll l, ll r, ll s, ll e) {
        if (s<=l && r<=e) return seg[node];
        if (e<l || r<s) return -1;
        ll m = (l+r)>>1;
        ll left = query(node<<1, l, m, s, e), right = query(node<<1|1, m+1, r, s, e);
        if (left==-1) return right;
        if (right==-1) return left;
        if (arr[left]<arr[right]) return left;
        return right;
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
    void update(ll node, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            seg[node] = val;
            return;
        }
        ll m = (l+r)>>1;
        if (tar<=m) update(node<<1, l, m, tar, val);
        else update(node<<1|1, m+1, r, tar, val);
        ll left = seg[node<<1], right = seg[node<<1|1];
        if (arr[left]<arr[right]) seg[node] = left;
        else seg[node] = right;
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
    }
};

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    SEG seg(arr);
    function<ll(ll, ll)> f = [&](ll lo, ll hi) -> ll {
        if (lo>hi) return 0;
        if (lo==hi) return arr[lo];
        ll idx = seg.query(lo, hi);
        return max({
            f(lo, idx-1),
            f(idx+1, hi),
            (hi-lo+1) * arr[idx]
        });
    };
    cout<<f(0, n-1)<<endl;
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

