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
constexpr ll MAX = 500'000;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

struct SEG {
    ll n;
    vl seg;
    SEG(ll n) : n(n), seg(n<<2) {}
    void update(ll tar, ll diff) {
        ll i=1, l=0, r=n-1;
        while (l<r) {
            ll m = (l+r)>>1;
            if (tar <= m) {
                i <<= 1;
                r = m;
            }
            else {
                i = i<<1|1;
                l = m+1;
            }
        }
        seg[i] += diff;
        while (i!=1) {
            i >>= 1;
            seg[i] = seg[i<<1] + seg[i<<1|1];
        }
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
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    ll m; cin>>m;
    vector<array<ll, 3>> query(m);
    for (i=0;i<m;i++) {
        // [r, l, idx]
        cin>>query[i][1]>>query[i][0];
        query[i][2] = i;
    }
    vl ans(m);
    sort(query.begin(), query.end());
    vl comp = arr;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (auto &x : arr)
        x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    // cout<<arr<<endl;
    vl prev(comp.size(), -1);
    SEG seg(n);
    ll qi = 0;
    for (i=0;i<n;i++) {
        ll x = arr[i];
        seg.update(i, 1);
        if (prev[x] != -1) seg.update(prev[x], -1);
        prev[x] = i;
        while (qi<m && query[qi][0]==i+1) {
            ans[query[qi][2]] = seg.query(query[qi][1]-1, query[qi][0]-1);
            qi++;
        }
        // cout<<prev<<endl;
        // for (j=0;j<n;j++) cout<<seg.query(j, j)<<' ';
        // cout<<endl;
    }
    for (auto x : ans) cout<<x<<endl;
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
