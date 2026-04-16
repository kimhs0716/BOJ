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

void solve(ll testcase) {
    ll i, j;
    ll r, c; cin>>r>>c;
    map<ll, ll> cnt;
    for (i=0;i<r*c;i++) {
        ll x; cin>>x;
        cnt[x]++;
    }
    ll odds = 0;
    for (auto [x, cc]: cnt) {
        if (cc&1) odds++;
    }
    if (c&1) {
        odds -= r;
    }
    if (odds<=0) cout<<"YES\n";
    else cout<<"NO\n";
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