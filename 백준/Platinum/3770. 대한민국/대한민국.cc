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
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            seg[i] += val;
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
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

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    ll n, m, k; cin>>n>>m>>k;
    vvl arr(n);
    while (k--) {
        ll a, b; cin>>a>>b;
        arr[a-1].push_back(b-1);
    }
    for (auto &x: arr) sort(x.begin(), x.end());
    // for (i=0;i<n;i++) {
    //     cout<<i<<": ";
    //     for (auto x: arr[i]) cout<<x<<' '; cout<<endl;
    // }
    SEG seg(m);
    ll ans = 0;
    for (i=0;i<n;i++) {
        for (auto x: arr[i]) {
            if (x != m-1) ans += seg.query(x+1, m-1);
            seg.update(x, 1);
        }
        // for (j=0;j<m;j++) cout<<seg.query(j, j)<<' '; cout<<endl;
    }
    cout<<"Test case "<<testcase<<": ";
    cout<<ans<<endl;
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

