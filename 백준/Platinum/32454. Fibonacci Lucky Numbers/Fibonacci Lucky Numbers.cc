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
// constexpr ll MAX = 65536;

void preprocess() {
    ll i, j, k;
}

ll modmul(ll a, ll b, ll m) {
    return ((__int128)a * (__int128)b) % m;
}

ll modpow(ll n, ll k, ll m) {
    ll ret=1;
    n %= m;
    while (k) {
        if (k&1) ret=modmul(ret, n, m);
        n = modmul(n, n, m);
        k>>=1;
    }
    return ret;
}


struct mat22 {
    ll arr[2][2];
};
mat22 mul(mat22 m1, mat22 m2){
    mat22 ret;
    ll mod = 10000000000;

    ret.arr[0][0] = (modmul(m1.arr[0][0], m2.arr[0][0], mod) + modmul(m1.arr[0][1], m2.arr[1][0], mod)) % mod;
    ret.arr[0][1] = (modmul(m1.arr[0][0], m2.arr[0][1], mod) + modmul(m1.arr[0][1], m2.arr[1][1], mod)) % mod;
    ret.arr[1][0] = (modmul(m1.arr[1][0], m2.arr[0][0], mod) + modmul(m1.arr[1][1], m2.arr[1][0], mod)) % mod;
    ret.arr[1][1] = (modmul(m1.arr[1][0], m2.arr[0][1], mod) + modmul(m1.arr[1][1], m2.arr[1][1], mod)) % mod;
    return ret;
}
mat22 pow(mat22 m, ll n){
    if(n == 1) return m;
    mat22 ret = pow(m, n / 2);
    ret = mul(ret, ret);
    if(n & 1)
        ret = mul(ret, m);
    return ret;
}

ll fib(ll n) {
    if (n==0) return 0;
    if (n<=2) return 1;
    return pow({1, 1, 1, 0}, n).arr[0][1];
}

constexpr ll mod = 15000000000;
constexpr ll pmod = 4000000000;
constexpr ll ppmod = 1600000000;
void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    ll ans=modpow(7, n, ppmod);
    ans=modpow(7, ans, pmod);
    ans=modpow(7, ans, mod);
    cout<<setfill('0')<<setw(10);
    cout<<fib(ans)<<endl;
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

