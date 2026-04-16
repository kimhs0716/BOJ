#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll modpow(ll a, ll b, ll rem){ll p=1;a%=rem;for(;b;b>>=1,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
pll extended_gcd(ll a, ll b) {
    if (b==0) return {1, 0};
    auto t=extended_gcd(b, a%b);
    return {t.second, t.first-t.second*(a/b)};
}
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first%m+m)%m;
}

void preprocess() {
    ll i, j;
}

// Usage: vl init { 2L개 이상의 초기 항 }; ll result = guess_nth_term(init, n);
// Note: 상수 계수 L차 선형 점화식의 n번째 항을 찾을 때 사용. 0-based
// O(L^2*logn)
vl berlekampMassey(vl s) {
    ll n=s.size(), L=0, m=1, d=0, coef=0;
    vl C(n), B(n), T(n);
    C[0]=B[0]=1;
    ll b=1;
    for (ll i=0;i<n;i++) {
        d=0;
        for (ll j=0;j<=L;j++)
            d=(d+C[j]*s[i-j])%MOD;
        if (d==0) {
            ++m;
            continue;
        }
        coef=d*modpow(b, MOD-2, MOD)%MOD;
        T=C;
        for (ll j=0;j+m<n;j++) {
            C[j+m]=(C[j+m]-coef*B[j])%MOD;
            if (C[j+m]<0) C[j+m]+=MOD;
        }
        if (2*L<=i) {
            L=i+1-L;
            B=T;
            b=d;
            m=1;
        }
        else {
            ++m;
        }
    }
    C.resize(L+1);
    vl tr(L);
    for (ll i=1;i<=L;++i)
        tr[i-1]=(MOD-C[i])%MOD;
    return tr;
}

ll get_nth(vl &S, vl &tr, ll k) {
    ll n=tr.size();
    auto combine=[&](vl &a, vl &b) {
        vl res(2*n+1);
        for (ll i=0;i<=n;i++)
            for (ll j=0;j<=n;j++)
                res[i+j]=(res[i+j]+a[i]*b[j])%MOD;
        for (ll i=2*n;i>n;i--)
            for (ll j=1;j<=n;j++)
                res[i-j]=(res[i-j]+res[i]*tr[j-1])%MOD;
        res.resize(n+1);
        return res;
    };

    vl pol(n+1), e(n+1);
    e[1]=1;
    pol[0]=1;
    for (++k;k>0;k>>=1) {
        if (k&1) pol=combine(pol, e);
        e=combine(e, e);
    }
    ll res=0;
    for (ll i=0;i<n;i++)
        res=(res+pol[i+1]*S[i])%MOD;
    return res;
}

ll guess_nth_term(vl x, ll n) {
    if (n<x.size()) return x[n];
    vl tr=berlekampMassey(x);
    if (tr.empty()) return x[0];
    return get_nth(x, tr, n);
}

void solve(ll tc) {
    ll i, j;
    ll n, k; cin>>n>>k;
    vl init(110);
    for (i=1;i<110;i++) {
        init[i] = (init[i-1] + modpow(i, k, MOD))%MOD;
    }
    cout<<guess_nth_term(init, n)<<endl;
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