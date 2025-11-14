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

struct node {
    ll l, r, sum, best;
};

struct SEG {
    ll n;
    vl arr;
    vector<node> seg;
    SEG(vl &arr) : n(arr.size()), arr(arr), seg(n<<2) {
        init(1, 0, n-1);
    }
    SEG(ll n) : n(n), arr(n), seg(n<<2) {

    }
    void init(ll i, ll l, ll r) {
        if (l==r) {
            ll x = arr[l];
            seg[i] = {x, x, x, x};
            return;
        }
        ll m = (l+r)>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        node left = seg[i<<1];
        node right = seg[i<<1|1];
        seg[i].l = max(left.l, left.sum + right.l);
        seg[i].r = max(right.r, right.sum + left.r);
        seg[i].sum = left.sum + right.sum;
        seg[i].best = max({left.best, right.best, left.r+right.l});
    }
    node query(ll i, ll l, ll r, ll s, ll e) {
        if (s<=l && r<=e) return seg[i];
        if (e<l || r<s) return {-INF, -INF, 0, -INF};
        ll m = (l+r)>>1;
        node left = query(i<<1, l, m, s, e);
        node right = query(i<<1|1, m+1, r, s, e);
        node ret{};
        ret.l = max(left.l, left.sum + right.l);
        ret.r = max(right.r, right.sum + left.r);
        ret.sum = left.sum + right.sum;
        ret.best = max({left.best, right.best, left.r+right.l});
        return ret;
    }
    node query(ll s, ll e) {
        if (s>e) return {-INF, -INF, 0, -INF};
        if (s==e) return {arr[s], arr[s], arr[s], arr[s]};
        return query(1, 0, n-1, s, e);
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            seg[i] = {val, val, val, val};
            return;
        }
        ll m = (l+r)>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        node left = seg[i<<1];
        node right = seg[i<<1|1];
        seg[i].l = max(left.l, left.sum + right.l);
        seg[i].r = max(right.r, right.sum + left.r);
        seg[i].sum = left.sum + right.sum;
        seg[i].best = max({left.best, right.best, left.r+right.l});
    }
    void update(ll tar, ll val) {
        arr[tar] += val;
        val = arr[tar];
        update(1, 0, n-1, tar, val);
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vector<array<ll, 3>> arr(n); // x, y, w
    map<ll, vp> y2xw;
    for (auto &[x, y, w] : arr) {
        cin>>x>>y>>w;
    }
    sort(arr.begin(), arr.end());
    ll idx = 0, prev = arr[0][0];
    for (i=0;i<n;i++) {
        auto [x, y, w] = arr[i];
        // cout<<x<<' '<<y<<' '<<w<<' '<<idx<<endl;
        if (x!=prev) {
            prev = x;
            idx++;
        }
        y2xw[y].push_back({idx, w});
    }
    for (auto &[y, v] : y2xw)
        sort(v.begin(), v.end());
    ll ans = 0;
    for (auto lo = y2xw.begin(); lo != y2xw.end(); lo++) {
        SEG seg(n);
        for (auto hi = lo; hi != y2xw.end(); hi++) {
            for (auto [x, w] : hi->second)
                seg.update(x, w);
            // cout<<seg.arr<<endl;
            ans = max(ans, seg.query(0, n-1).best);
        }
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

