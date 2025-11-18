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

struct LAZY {
    ll n;
    vl arr, seg, lazy;
    LAZY(vl &a) : n(a.size()), arr(a), seg(n<<2), lazy(n<<2) {
        init(1, 0, n-1);
    }
    LAZY(ll _n) : n(_n), arr(n), seg(n<<2), lazy(n<<2) {
        init(1, 0, n-1);
    }
    void init(ll i, ll l, ll r) {
        if (l==r) {
            seg[i] = arr[l];
            return;
        }
        ll m = l+r>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
    void update_lazy(ll i, ll l, ll r) {
        if (lazy[i]) {
            seg[i] += (r-l+1) * lazy[i];
            if (l!=r) {
                lazy[i<<1] += lazy[i];
                lazy[i<<1|1] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    void update_range(ll i, ll l, ll r, ll s, ll e, ll val) {
        update_lazy(i, l, r);
        if (e<l || r<s) return;
        if (s<=l && r<=e) {
            seg[i] += (r-l+1) * val;
            if (l!=r) {
                lazy[i<<1] += val;
                lazy[i<<1|1] += val;
            }
            return;
        }
        ll m=l+r>>1;
        update_range(i<<1, l, m, s, e, val);
        update_range(i<<1|1, m+1, r, s, e, val);
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
    void update(ll s, ll e, ll val) {
        update_range(1, 0, n-1, s, e, val);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        update_lazy(i, l, r);
        if (s<=l && r<=e) return seg[i];
        if (e<l || r<s) return 0;
        ll m=l+r>>1;
        return query(i<<1, l, m, s, e) + query(i<<1|1, m+1, r, s, e);
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    ll n, m; cin>>n>>m;
    vvl ch(n);
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        if (!i) continue;
        ch[x-1].push_back(i);
    }
    vl in(n), out(n);
    function<ll(ll, ll)> dfs = [&ch, &in, &out, &dfs](ll cur, ll time) {
        in[cur] = time;
        for (ll nxt: ch[cur]) {
            time = dfs(nxt, time+1);
        }
        out[cur] = time;
        return time;
    };
    dfs(0, 0);
    // for (i=0;i<n;i++) cout<<i<<": "<<in[i]<<' '<<out[i]<<endl;
    LAZY seg(n);
    while (m--) {
        ll a, b, c; cin>>a>>b;
        if (a==1) {
            cin>>c;
            seg.update(in[b-1], out[b-1], c);
        }
        else {
            cout<<seg.query(in[b-1], in[b-1])<<endl;
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

