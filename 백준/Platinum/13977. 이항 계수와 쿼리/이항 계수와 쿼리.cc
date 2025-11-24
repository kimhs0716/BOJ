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

pll extgcd(ll a, ll b) {
    if (b==0) return {1, 0};
    auto [p, q]=extgcd(b, a%b);
    return {q, p-q*(a/b)};
}

ll modinv(ll a, ll m) {
    if (gcd(a, m) != 1) return -1;
    return (extgcd(a, m).first%m+m)%m;
}

constexpr ll MAX = 4000000;
vl fac(MAX+1), inv_fac(MAX+1);
void preprocess() {
    ll i, j;
    fac[0] = 1;
    for (i=1;i<=MAX;i++)
        fac[i] = fac[i-1]*i%MOD;
    inv_fac[MAX] = modinv(fac[MAX], MOD);
    for (i=MAX-1;i>=0;i--)
        inv_fac[i] = inv_fac[i+1] * (i+1) % MOD;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    while (n--) {
        ll a, b; cin>>a>>b;
        cout<<fac[a]*inv_fac[b]%MOD*inv_fac[a-b]%MOD<<endl;
    }
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

