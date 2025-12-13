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

pll merge(pll a, pll b) {
    if (a.first == b.first) {
        if (a.first==0) return {0, 1};
        return {a.first, (a.second + b.second) % MOD};
    }
    return max(a, b);
}

struct SEG {
    ll n;
    vp seg;
    SEG(ll n) : n(n), seg(n<<2, {0, 1}) {}
    void update(ll i, ll l, ll r, ll tar, pll val) {
        if (l==r) {
            seg[i] = val;
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        seg[i] = merge(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll tar, pll val) {
        update(1, 0, n-1, tar, val);
    }
    pll query(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return {0, 1};
        if (s<=l && r<=e) return seg[i];
        ll m=l+r>>1;
        return merge(query(i<<1, l, m, s, e), query(i<<1|1, m+1, r, s, e));
    }
    pll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vp arr(n);
    for (i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), [](const pll a, const pll b) {
        if (a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    });
    SEG seg(n);
    for (auto [x, idx] : arr) {
        auto [mx, cnt] = seg.query(idx, n-1);
        seg.update(idx, {mx+1, cnt});
        // for (i=0;i<n;i++) cout<<seg.query(i, i).first<<' '; cout<<endl;
        // for (i=0;i<n;i++) cout<<seg.query(i, i).second<<' '; cout<<endl;
    }
    auto [mx, cnt] = seg.seg[1];
    cout<<mx<<' '<<cnt<<endl;
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

