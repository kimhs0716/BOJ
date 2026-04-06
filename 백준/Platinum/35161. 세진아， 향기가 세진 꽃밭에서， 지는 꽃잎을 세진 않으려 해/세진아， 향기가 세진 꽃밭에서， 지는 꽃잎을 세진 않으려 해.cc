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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ld eps = 1e-8;

constexpr ll MAX = 100'100;
vl p(MAX), t(MAX);
void preprocess() {
    ll i, j;
    p[0] = 1;
    for (i=1;i<MAX;i++) p[i] = (p[i-1]<<1) % MOD;
    t[0] = 10;
    for (i=1;i<MAX;i++) {
        t[i] = (t[i-1] + p[i+2]) % MOD;
        if (!(i&1)) t[i] = (t[i]+p[i>>1]) % MOD;
    }
    // for (i=0;i<10;i++) cout<<t[i]<<' '; cout<<endl;
    vl pre(MAX);
    for (i=1;i<MAX;i++) {
        pre[i] = pre[i-1] + t[i-1];
    }
    swap(pre, t);
}

void solve(ll tc){
    int i, j;
    ll n, m; cin>>n>>m;
    ll ans = 12;
    ans += t[n-2];
    ans += t[m-2];
    cout<<ans%MOD<<endl;
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
