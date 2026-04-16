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

pll extended_gcd(ll a, ll b) {
    if (b==0) return {1, 0};
    auto t=extended_gcd(b, a%b);
    return {t.second, t.first-t.second*(a/b)};
}

ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first%m+m)%m;
}

ll chinese_remainder(vl &a, vl &n, ll s=0) {
    ll size=a.size();
    if (s==size-1) return a[s];
    ll tmp=modinverse(n[s], n[s+1]);
    ll tmp2=(tmp*(a[s+1]-a[s])%n[s+1]+n[s+1])%n[s+1];
    ll ora=a[s+1];
    ll tgcd=gcd(n[s],n[s+1]);
    if ((a[s+1]-a[s])%tgcd!=0) return -1;
    a[s+1]=a[s]+n[s]/tgcd*tmp2;
    n[s+1]*=n[s]/tgcd;
    ll ret=chinese_remainder(a, n, s+1);
    n[s+1]/=n[s]/tgcd;
    a[s+1]=ora;
    return ret;
}

void solve(ll testcase) {
    ll i, j;
    ll m, n, x, y; cin >> m >> n >> x >> y;
    vl a {x, y};
    vl mod {m, n};
    cout << chinese_remainder(a, mod) << endl;
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