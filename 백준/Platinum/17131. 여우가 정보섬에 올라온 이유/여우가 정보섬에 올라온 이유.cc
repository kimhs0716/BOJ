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

void preprocess() {
    ll i, j;
}

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
};

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    set<ll> xs, ys;
    vp arr(n);
    for (auto &[x, y] : arr) {
        cin>>x>>y;
        xs.insert(x);
        ys.insert(y);
    }
    map<ll, ll> xm, ym;
    for (auto x : xs) xm[x] = xm.size();
    for (auto y : ys) ym[y] = ym.size();
    for (auto &[x, y] : arr) {
        x = xm[x];
        y = ym[y];
    }
    // for (auto [x, y] : arr) cout<<x<<' '<<y<<endl;
    sort(arr.begin(), arr.end(), [](const pll &a, const pll &b) {
        return a.second>b.second;
    });
    SEG seg(xm.size());
    ll ans = 0, idx = 0;
    for (i=ym.size()-1;i>=0;i--) {
        // for (j=0;j<xm.size();j++) cout<<seg.query(i, i)<<' '; cout<<endl;
        vp temp;
        while (idx<n && arr[idx].second==i) {
            temp.push_back(arr[idx++]);
        }
        for (auto [x, y] : temp) {
            ans += seg.query(0, x-1) * seg.query(x+1, xm.size()) % MOD;
            ans %= MOD;
        }
        for (auto [x, y] : temp) {
            seg.update(x, 1);
        }
        // cout<<temp.size()<<endl;
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
