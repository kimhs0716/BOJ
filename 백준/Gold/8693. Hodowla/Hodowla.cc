#include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;

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

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    vvl arr(n, vl(n)); cin>>arr;
    vvl toggle(n+2, vl(n+2));
    ll q; cin>>q;
    while (q--) {
        ll r1, c1, r2, c2; cin>>c1>>r1>>c2>>r2;
        toggle[r1][c1] ^= 1;
        toggle[r1][c2+1] ^= 1;
        toggle[r2+1][c1] ^= 1;
        toggle[r2+1][c2+1] ^= 1;
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            toggle[i][j] ^= toggle[i-1][j] ^ toggle[i][j-1] ^ toggle[i-1][j-1];
        }
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            cout<<(arr[i-1][j-1]^toggle[i][j])<<' ';
        }
        cout<<endl;
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