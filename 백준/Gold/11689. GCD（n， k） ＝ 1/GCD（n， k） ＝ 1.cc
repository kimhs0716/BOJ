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

ll powm(ll n, ll k) {
    ll ret=1;
    while (k) {
        if (k&1) ret*=n;
        n*=n;
        k>>=1;
    }
    return ret;
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

bool is_prime(ll n) {
    if (n<2 || n%2==0 || n%3==0) return n==2 || n==3;
    ll k=__builtin_ctzll(n-1), d=n-1>>k;
    for (ll a: { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
        ll p=modpow(a%n, d, n), i=k;
        while (p!=1 && p!=n-1 && a%n && i--) p = modmul(p, p, n);
        if (p!=n-1 && i!=k) return 0;
    }
    return 1;
}

ll pollard(ll n) {
    auto f=[n](ll x) { return (modmul(x, x, n)+3)%n; };
    ll x=0, y=0, t=30, p=2, i=1, q;
    while (t++ % 40 || gcd(p, n)==1) {
        if (x==y) x=++i, y=f(x);
        if (q=modmul(p, abs(x-y), n)) p=q;
        x=f(x), y=f(f(y));
    }
    return gcd(p, n);
}
void factor(ll n, vl &ret) {
    if (n==1) return;
    if (is_prime(n)) {
        ret.push_back(n);
        return;
    }
    ll d=pollard(n);
    factor(d, ret);
    factor(n/d, ret);
}

vl factor(ll n) {
    vl ret;
    factor(n, ret);
    sort(ret.begin(), ret.end());
    return ret;
}

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    vl f = factor(n);
    map<ll, ll> cnt;
    for (auto x: f) cnt[x]++;
    ll ans=1;
    for (auto &[p, e] : cnt) {
        ll pe=powm(p, e-1);
        ans *= pe * (p-1);
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