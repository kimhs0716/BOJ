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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, q; cin>>n>>q;
    vvl adj(n, vl(n)); cin>>adj;
    vector dist(n+1, vvl(n, vl(n, INF)));
    for (i=0;i<n;i++)
        for (j=0;j<n;j++) {
            dist[i][j][j] = 0;
            if (adj[i][j]) dist[0][i][j] = adj[i][j];
        }
    for (ll m=0;m<n;m++) {
        for (ll s=0;s<n;s++) {
            for (ll e=0;e<n;e++) {
                dist[m+1][s][e] = dist[m][s][e];
                if (dist[m][s][m]!=INF && dist[m][m][e]!=INF)
                    dist[m+1][s][e] = min(dist[m+1][s][e], dist[m][s][m] + dist[m][m][e]);
            }
        }
    }
    // for (i=0;i<=n;i++) {
    //     for (j=0;j<n;j++) {
    //         for (k=0;k<n;k++)
    //             if (dist[i][j][k]==INF) cout<<"I ";
    //             else cout<<dist[i][j][k]<<' ';
    //         cout<<endl;
    //     }
    //     cout<<"=============\n";
    // }
    while (q--) {
        ll c, s, e; cin>>c>>s>>e;
        c--;
        --s; --e;
        ll ans = dist[c][s][e];
        if (ans==INF) cout<<"-1\n";
        else cout<<ans<<endl;
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

