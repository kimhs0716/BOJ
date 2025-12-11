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
constexpr ll INF = 1e15;

struct SEG {
    ll n;
    vl arr, seg;
    function<ll(ll, ll)> f;
    ll id;
    SEG(vl &a, function<ll(ll, ll)> f, ll id) : n(a.size()), arr(a), seg(n<<2), f(std::move(f)), id(id) {
        init(1, 0, n-1);
    }
    void init(ll i, ll l, ll r) {
        if (l==r) {
            seg[i] = arr[l];
            return;
        }
        ll m = (l+r)>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        seg[i] = f(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            seg[i] = arr[tar] = val;
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        seg[i] = f(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return id;
        if (s<=l && r<=e) return seg[i];
        ll m=l+r>>1;
        return f(query(i<<1, l, m, s, e), query(i<<1|1, m+1, r, s, e));
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n, m; cin>>n>>m;
    vl arr(n);
    iota(arr.begin(), arr.end(), 0);
    SEG mins(arr, [](ll x, ll y) { return min(x, y); }, INF);
    SEG maxs(arr, [](ll x, ll y) { return max(x, y); }, -INF);
    while (m--) {
        ll a, b, c; cin>>a>>b>>c;
        if (a==1) {
            ll mn = mins.query(b, c);
            ll mx = maxs.query(b, c);
            if (mn==b && mx==c) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else {
            swap(arr[b], arr[c]);
            mins.update(b, arr[b]);
            mins.update(c, arr[c]);
            maxs.update(b, arr[b]);
            maxs.update(c, arr[c]);
        }
    }
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}

