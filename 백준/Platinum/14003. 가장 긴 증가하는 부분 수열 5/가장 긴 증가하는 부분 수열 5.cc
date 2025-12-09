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
    vl arr;
    vp seg;
    SEG(vl &a) : n(a.size()), arr(a), seg(n<<2) {
        init(1, 0, n-1);
    }
    SEG(ll n) : n(n), arr(n), seg(n<<2, {0, -1}) {}
    void init(ll i, ll l, ll r) {
        if (l==r) {
            seg[i] = {arr[l], l};
            return;
        }
        ll m=l+r>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            arr[l] = val;
            seg[i] = {arr[l], l};
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
    }
    pll query(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return {0, -1};
        if (s<=l && r<=e) return seg[i];
        ll m=l+r>>1;
        return max(query(i<<1, l, m, s, e), query(i<<1|1, m+1, r, s, e));
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
    vl pos(n);
    for (i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second = -i;
        pos[i] = arr[i].first;
    }
    sort(arr.rbegin(), arr.rend());
    SEG seg(n);
    vl nxt(n), len(n);
    for (auto [x, idx] : arr) {
        idx = -idx;
        auto [mx, mi] = seg.query(idx, n-1);
        nxt[idx] = mi;
        len[idx] = mx+1;
        seg.update(idx, mx+1);
    }
    // for (i=0;i<n;i++) cout<<seg.query(i, i).first<<' '; cout<<endl;
    auto [mx, cur] = seg.query(0, n-1);
    cout<<mx<<endl;
    while (cur!=-1) {
        cout<<pos[cur]<<' ';
        cur = nxt[cur];
    }
    cout<<endl;
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

