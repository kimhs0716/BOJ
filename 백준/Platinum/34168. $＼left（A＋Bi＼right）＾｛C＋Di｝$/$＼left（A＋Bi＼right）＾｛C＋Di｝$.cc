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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j, k;
    ll a, b, m; cin>>a>>b>>m;
    __int128 ans;
    if (a==0) {
        if (b==0) {
            ans = m;
        }
        else if (b==1 || b==-1) {
            ans = (__int128)(2*m+1)*(__int128)(2*(m/2)+1);
        }
        else {
            ans = 2*(m/2)+1;
        }
    }
    else if (b==0) {
        if (a==1) {
            ans = (__int128)(2*m+1)*(__int128)(2*m+1);
        }
        else if (a==-1) {
            ans = 4*m+1;
        }
        else {
            ans = 2*m+1;
        }
    }
    else if (a==b) {
        ans = (2*(m/4)+1);
    }
    else if (a==-b) {
        ans = (2*(m/4)+1);
    }
    else {
        ans = 1;
    }
    cout<<(ll)(ans%MOD)<<endl;
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