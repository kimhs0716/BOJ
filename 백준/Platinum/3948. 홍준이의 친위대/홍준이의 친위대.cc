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

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = (ll)1e18+1;

ll comb[25][25];
void preprocess() {
    ll i, j;
    for (i=0;i<25;i++) comb[i][0] = comb[i][i] = 1;
    for (i=1;i<25;i++) {
        for (j=1;j<i;j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
    }
}

void solve(ll tc){
    ll i, j;
    vl dp(21);
    dp[0] = 1;
    dp[1] = 1;
    for (i=2;i<=20;i++) {
        for (ll k=0;k<=i-1;k+=2) { // max elem is at k-th pos
            dp[i] += dp[k] * dp[i-1-k] * comb[i-1][k];
        }
    }
    ll t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        if (n==1) cout<<1<<endl;
        else cout<<2*dp[n]<<endl;
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
