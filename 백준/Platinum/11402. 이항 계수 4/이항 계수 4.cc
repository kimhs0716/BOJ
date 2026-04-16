#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
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
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

ll modmul(ll a, ll b, ll m) {
    return ll((__int128)a*(__int128)b%m);
}

ll modpow(ll n, ll k, ll m) {
    ll ret=1;
    n%=m;
    while (k) {
        if (k&1) ret=modmul(ret, n, m);
        n=modmul(n, n, m);
        k>>=1;
    }
    return ret;
}

// binomial은 별도로 구현, binomial(n, m, p) = 0 if n < m
// n, m < p인 경우만 미리 구현
ll binomial(ll n, ll m, ll p) {
    static vl fac(p), invfac(p);
    static bool computed = false;
    if (!computed) {
        fac[0]=1;
        for (ll i=1;i<p;i++) fac[i]=fac[i-1]*i%p;
        invfac[p-1] = modpow(fac[p-1], p-2, p);
        for (ll i=p-2;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%p;
    }
    return fac[n] * invfac[m] % p * invfac[n-m] % p;
}
ll lucas(ll n, ll m, ll p){
    if(m<0 || m>n) return 0;
    ll res = 1;
    while (n>0 || m>0) {
        ll n_i=n%p;
        ll m_i=m%p;
        if (m_i>n_i) return 0;
        res=res*binomial(n_i, m_i, p)%p;
        n/=p;
        m/=p;
    }
    return res;
}

void solve(ll testcase) {
    ll i, j;
    ll n, k, p; cin>>n>>k>>p;
    cout<<lucas(n, k, p)<<endl;
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