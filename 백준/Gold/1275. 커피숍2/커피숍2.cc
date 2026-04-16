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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

// usage: SEG(n, arr); update(tar, val); ll sum = query(qs, qe);
// memo : 0-indexed
struct SEG {
    ll n;
    vl seg, arr;

    SEG(ll n, vl& arr): n(n),arr(arr),seg(n<<2){
        init(1,0,n-1);
    }

    void init(ll node,ll l,ll r) {
        if (l==r) {
            seg[node]=arr[l];
            return;
        }
        ll m=(l+r)>>1;
        init(node<<1,l,m);
        init(node<<1|1,m+1,r);
        seg[node]=seg[node<<1]+seg[node<<1|1];
    }

    ll range_sum(ll node, ll l, ll r, ll s, ll e) {
        if (r<s||e<l) return 0;
        if (s<=l&&r<=e) return seg[node];
        ll m=(l+r)>>1;
        return range_sum(node<<1,l,m,s,e) + range_sum(node<<1|1,m+1,r,s,e);
    }

    void point_update(ll node, ll l, ll r, ll tar, ll val) {
        if (r<tar||tar<l) return;
        if (l==r) {
            seg[node]=val;
            return;
        }
        ll m=(l+r)>>1;
        point_update(node<<1,l,m,tar,val);
        point_update(node<<1|1,m+1,r,tar,val);
        seg[node]=seg[node<<1]+seg[node<<1|1];
    }
    void update(ll tar,ll val){point_update(1,0,n-1,tar,val);}
    ll query(ll s,ll e){return range_sum(1,0,n-1,s,e);}
};

void solve(ll testcase) {
    ll i, j, k;
    ll n, q; cin>>n>>q;
    vl arr(n); cin>>arr;
    SEG seg(n, arr);
    while (q--) {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        if (a>b) swap(a, b);
        cout<<seg.query(a-1, b-1)<<endl;
        seg.update(c-1, d);
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