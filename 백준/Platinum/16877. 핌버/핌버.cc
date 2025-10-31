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
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

unsigned char g[3000001];
void solve(ll testcase) {
    ll i, j, k;
    int fib[32] = {1, 2};
    for (i=2;i<32;i++) fib[i] = fib[i-1] + fib[i-2];
    g[0] = 0;
    for (i=1;i<=3000000;i++) {
        ll t = 0;
        for (j=0;j<32;j++) {
            int f = fib[j];
            if (f>i) break;
            t |= (1LL<<g[i-f]);
        }
        while (t&1) {
            t>>=1;
            g[i]++;
        }
    }
    ll ans = 0;
    ll n; cin>>n;
    while (n--) {
        ll x; cin>>x;
        ans ^= g[x];
    }
    cout<<(ans ? "koosaga" : "cubelover")<<endl;
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

