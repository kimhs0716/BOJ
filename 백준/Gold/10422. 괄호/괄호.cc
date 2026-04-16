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

constexpr ll MAX = 10001;
vl fac(MAX);
void preprocess() {
    ll i, j;
    fac[0]=1;
    for (i=1;i<MAX;i++) fac[i]=fac[i-1]*i%MOD;
}

ll modpow(ll n, ll k) {
    ll ret=1;
    while (k) {
        if (k&1) ret=ret*n%MOD;
        n=n*n%MOD;
        k>>=1;
    }
    return ret;
}

ll modinv(ll n) {
    return modpow(n, MOD-2);
}

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    if (n&1) cout<<0<<endl;
    else {
        n >>= 1;
        cout<<fac[2*n]*modpow(modinv(fac[n]), 2)%MOD*modinv(n+1)%MOD<<endl;
    }
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