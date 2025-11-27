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
    vl arr, len, cover;
    SEG(ll n) : n(n), arr(n), len(n<<2), cover(n<<2) {
        // init(1, 0, n-1);
    }
    // void init(ll i, ll l, ll r) {
    //     if (l==r) {
    //         seg[i] = arr[l];
    //         return;
    //     }
    //     ll m=l+r>>1;
    //     init(i<<1, l, m);
    //     init(i<<1|1, m+1, r);
    //     seg[i] = seg[i<<1] + seg[i<<1|1];
    // }
    void update(ll i, ll l, ll r, ll s, ll e, ll val) {
        if (r<s || e<l) return;
        if (s<=l && r<=e) {
            cover[i] += val;
        }
        else {
            ll m=l+r>>1;
            if (s<=m) update(i<<1, l, m, s, e, val);
            if (m+1<=e) update(i<<1|1, m+1, r, s, e, val);
        }
        if (cover[i]) len[i] = r-l+1;
        else {
            len[i] = (l==r) ? 0 : len[i<<1] + len[i<<1|1];
        }
    }
    void update(ll s, ll e, ll val) {
        update(1, 0, n-1, s, e, val);
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    ll ans = 0;
    map<ll, pair<vp, vp>> queries;
    while (n--) {
        ll a, b, c, d; cin>>a>>b>>c>>d;
        queries[a].first.push_back({b, d});
        queries[c].second.push_back({b, d});
    }
    SEG seg(30000);
    ll prev_x = queries.begin()->first;
    for (auto &[x, p] : queries) {
        auto &[in, out] = p;
        ans += (x-prev_x) * seg.len[1];
        for (auto [y1, y2] : in) seg.update(y1, y2-1, 1);
        for (auto [y1, y2] : out) seg.update(y1, y2-1, -1);
        prev_x = x;
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

