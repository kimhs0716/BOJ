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
    vl arr, seg;
    SEG(vl &arr) : n(arr.size()), seg(n<<2), arr(arr) {
        init(1, 0, n-1);
    }
    void init(ll i, ll l, ll r) {
        if (l==r) {
            seg[i] = arr[l]!=0;
            return;
        }
        ll m = (l+r)>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
    void update(ll i, ll l, ll r, ll tar, ll diff) {
        if (l==r) {
            if (arr[l]==0 && diff!=0) seg[i] = 1;
            arr[l] = (arr[l] + diff) % 26;
            if (arr[l]==0 && diff!=0) seg[i] = 0;
            return;
        }
        ll m = (l+r)>>1;
        if (tar <= m) update(i<<1, l, m, tar, diff);
        else update(i<<1|1, m+1, r, tar, diff);
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
    void update(ll tar, ll diff) {
        update(1, 0, n-1, tar, diff);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return seg[i];
        ll m = (l+r)>>1;
        return query(i<<1, l, m, s, e) + query(i<<1|1, m+1, r, s, e);
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
};

void solve(ll tc){
    ll i, j;
    ll n, q; cin>>n>>q;
    string s; cin>>s;
    vl diff(n);
    diff[0] = s[0]-'A';
    for (i=1;i<n;i++) {
        diff[i] = (s[i] - s[i-1] + 26) % 26;
    }
    // cout<<diff<<endl;
    SEG seg(diff);
    while (q--) {
        ll a, b, c; cin>>a>>b>>c;
        if (a==1) {
            ll ans = seg.query(b-1, c-1);
            if (seg.arr[b-1]==0) ans++;
            cout<<ans<<endl;
        }
        else {
            seg.update(b-1, 1);
            if (c<n) seg.update(c, 25);
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
