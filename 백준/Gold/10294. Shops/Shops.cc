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
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vvl arr(5, vl(n)); cin>>arr;
    ll total = (1<<5);
    vl valid;
    for (ll mask = 0; mask < total; mask++) {
        if ((mask & (mask << 1)) == 0) valid.push_back(mask);
    }
    vvl dp(n, vl(total));
    for (ll i : valid) {
        ll t = 0;
        for (j=0;j<5;j++) {
            if ((i>>j)&1) t += arr[j][0];
        }
        dp[0][i] = t;
    }
    for (i=1;i<n;i++) {
        for (ll c : valid) {
            ll s = 0;
            for (j=0;j<5;j++) {
                if ((c>>j)&1) s += arr[j][i];
            }
            for (ll p : valid) {
                if (c&p) continue;
                dp[i][c] = max(dp[i][c], dp[i-1][p]);
            }
            dp[i][c] += s;
        }
    }
    // for (auto &x : dp) cout<<x<<endl;
    cout<<*max_element(dp[n-1].begin(), dp[n-1].end())<<endl;
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
