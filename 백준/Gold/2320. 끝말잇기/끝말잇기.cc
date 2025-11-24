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

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vl s(n), e(n), len(n);
    for (i=0;i<n;i++) {
        string t; cin>>t;
        s[i] = t[0];
        e[i] = t.back();
        len[i] = t.size();
    }
    vvl dp(1<<n, vl(n, -1));
    ll ans = 0;
    for (i=0;i<n;i++) {
        dp[1<<i][i] = len[i];
        ans = max(ans, len[i]);
    }
    for (ll mask=0;mask<(1<<n);mask++) {
        for (i=0;i<n;i++) {
            // if (!((mask>>i)&1)) continue;
            if (dp[mask][i]==-1) continue;
            for (j=0;j<n;j++) {
                if (e[i] != s[j]) continue;
                if ((mask>>j)&1) continue;
                dp[mask|(1<<j)][j] = max(dp[mask|(1<<j)][j], dp[mask][i] + len[j]);
                ans = max(ans, dp[mask|(1<<j)][j]);
            }
        }
    }
    cout<<ans<<endl;
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

