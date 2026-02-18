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

ll modpow(ll n, ll k) {
    ll ret = 1;
    while (k) {
        if (k&1) ret = ret*n%MOD;
        n = n*n%MOD;
        k >>= 1;
    }
    return ret;
}

void solve(ll tc){
    ll i, j;
    constexpr ll MAX = 400000;
    vl fac(MAX+1), inv_fac(MAX+1);
    fac[0] = 1;
    for (i=1;i<=MAX;i++) fac[i] = fac[i-1]*i%MOD;
    inv_fac[MAX] = modpow(fac[MAX], MOD-2);
    for (i=MAX-1;i>=0;i--) inv_fac[i] = inv_fac[i+1]*(i+1)%MOD;
    function<ll(ll, ll)> comb = [&fac, &inv_fac](ll n, ll r) {
        return fac[n] * inv_fac[r] % MOD * inv_fac[n-r] % MOD;
    };
    ll ans = 0, n; cin>>n;
    for (i=3;i<=n;i++) ans = (ans+comb(i<<1, i)) % MOD;
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
