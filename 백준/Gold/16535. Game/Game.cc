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
    vl arr(n); cin>>arr;
    vvl dp(n, vl(n, INF));
    function<ll(ll, ll)> f = [&arr, &dp, &f](ll left, ll right) -> ll {
        if (left==right) return 1LL;
        if (left>right) return 0LL;
        ll &ret = dp[left][right];
        if (ret!=INF) return ret;
        ret = 1+f(left+1, right);
        for (ll i=left+1;i<=right;i++) {
            if (arr[left] == arr[i]) {
                ret = min(ret, f(left+1, i-1) + f(i+1, right));
            }
        }
        return ret;
    };
    cout<<n-f(0, n-1)<<endl;
    // for (i=0;i<n;i++) {
    //     for (j=0;j<n;j++)
    //         if (dp[i][j]<INF) cout<<dp[i][j]<<' ';
    //         else cout<<-1<<' ';
    //     cout<<endl;
    // }
    // cout<<f(0, 2)<<endl;
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