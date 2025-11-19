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
    vl arr, seg, add, mul;
    LAZY(vl &a) : n(a.size()), arr(a), seg(n<<2), add(n<<2), mul(n<<2, 1) {
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
        seg[i] = (seg[i<<1] + seg[i<<1|1]) % MOD;
    }
    void update_lazy(ll i, ll l, ll r) {
        if (add[i] || mul[i]!=1) {
            ll len = r-l+1;
            seg[i] = seg[i] * mul[i] % MOD;
            seg[i] = (seg[i] + len*add[i]) % MOD;
            if (l!=r) {
                mul[i<<1] = mul[i<<1]*mul[i]%MOD;
                add[i<<1] = (add[i<<1]*mul[i]%MOD+add[i])%MOD;
                mul[i<<1|1] = mul[i<<1|1]*mul[i]%MOD;
                add[i<<1|1] = (add[i<<1|1]*mul[i]%MOD+add[i])%MOD;
            }
            add[i] = 0;
            mul[i] = 1;
        }
    }
    void update_range(ll i, ll l, ll r, ll s, ll e, ll a, ll b) {
        update_lazy(i, l, r);
        if (e<l || r<s) return;
        if (s<=l && r<=e) {
            ll len = r-l+1;
            seg[i] = (seg[i]*a%MOD+len*b)%MOD;
            if (l!=r) {
                mul[i<<1] = mul[i<<1]*a%MOD;
                add[i<<1] = (add[i<<1]*a%MOD+b)%MOD;
                mul[i<<1|1] = mul[i<<1|1]*a%MOD;
                add[i<<1|1] = (add[i<<1|1]*a%MOD+b)%MOD;
            }
            return;
        }
        ll m=l+r>>1;
        update_range(i<<1, l, m, s, e, a, b);
        update_range(i<<1|1, m+1, r, s, e, a, b);
        seg[i] = (seg[i<<1] + seg[i<<1|1]) % MOD;
    }
    void update(ll s, ll e, ll a, ll b) {
        update_range(1, 0, n-1, s, e, a, b);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        update_lazy(i, l, r);
        if (s<=l && r<=e) return seg[i];
        if (e<l || r<s) return 0;
        ll m=l+r>>1;
        return (query(i<<1, l, m, s, e) + query(i<<1|1, m+1, r, s, e)) % MOD;
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
    ll n, m; cin>>n;
    vl arr(n); cin>>arr;
    LAZY seg(arr);
    cin>>m;
    while (m--) {
        ll a, b, c, d; cin>>a>>b>>c;
        if (a==4) {
            cout<<seg.query(b-1, c-1)<<endl;
        }
        else {
            cin>>d;
            if (a==1) {
                seg.update(b-1, c-1, 1, d);
            }
            else if (a==2) {
                seg.update(b-1, c-1, d, 0);
            }
            else {
                seg.update(b-1, c-1, 0, d);
            }
        }
        // for (i=0;i<n;i++) cout<<seg.query(i, i)<<' '; cout<<endl;
    }
    // for (i=0;i<n;i++) cout<<seg.query(i, i)<<' '; cout<<endl;
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

