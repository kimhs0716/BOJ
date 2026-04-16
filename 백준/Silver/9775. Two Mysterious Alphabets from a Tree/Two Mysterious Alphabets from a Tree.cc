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
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
constexpr ll MAX = 1'000'000;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vvl arr(n, vl(n));
    for (i=0;i<n;i++) {
        for (j=0;j<=i;j++) cin>>arr[i][j];
    }
    vvl dp1(n, vl(n)), dp2(n, vl(n));
    dp1[0][0] = arr[0][0];
    dp2[0][0] = arr[0][0] * arr[0][0];
    for (i=1;i<n;i++) {
        dp1[i][0] = dp1[i-1][0] + arr[i][0];
        dp2[i][0] = dp2[i-1][0] + arr[i][0]*arr[i][0];
        dp1[i][i] = dp1[i-1][i-1] + arr[i][i];
        dp2[i][i] = dp2[i-1][i-1] + arr[i][i]*arr[i][i];
        for (j=1;j<i;j++) {
            dp1[i][j] = max(dp1[i-1][j-1], dp1[i-1][j]) + arr[i][j];
            dp2[i][j] = max(dp2[i-1][j-1], dp2[i-1][j]) + arr[i][j]*arr[i][j];
        }
    }
    ll ans1=0, ans2=0;
    for (i=0;i<n;i++) {
        ans1=max(ans1, dp1[n-1][i]);
        ans2=max(ans2, dp2[n-1][i]);
    }
    cout<<ans2<<' '<<ans1<<endl;
    cout<<"abcdefghijklmnopqrstuvwxyz"[ans2%26];
    cout<<"abcdefghijklmnopqrstuvwxyz"[ans1%26]<<endl;
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