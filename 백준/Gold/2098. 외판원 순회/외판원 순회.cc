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
    vvl adj(n, vl(n));
    cin>>adj;
    vvl dp(1<<n, vl(n, INF));
    dp[1][0] = 0;
    for (ll mask=1;mask<(1<<n);mask++) {
        if ((mask&1)==0) continue;
        // v -> u로 이동
        for (ll v=0;v<n;v++) {
            if (((mask>>v)&1) == 0) continue; // v를 방문 안함
            if (dp[mask][v] == INF) continue; // 방문 불가
            for (ll u=0;u<n;u++) {
                if ((mask>>u)&1) continue; // 이미 방문
                if (adj[v][u]==0) continue; // 간선 없음
                dp[mask|(1<<u)][u] = min(dp[mask|(1<<u)][u], dp[mask][v] + adj[v][u]);
            }
        }
    }
    ll ans=INF;
    ll mask = (1<<n)-1;
    for (i=0;i<n;i++) {
        if (dp[mask][i]==INF) continue;
        if (adj[i][0]==0) continue;
        ans = min(ans, dp[mask][i]+adj[i][0]);
    }
    cout<<ans<<endl;
    // for (auto &x: dp) {
    //     for (auto y: x) {
    //         if (y==INF) cout<<"I ";
    //         else cout<<y<<' ';
    //     }
    //     cout<<endl;
    // }
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