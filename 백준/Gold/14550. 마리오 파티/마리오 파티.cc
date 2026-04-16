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
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

bool check(vector<array<ll, 3>> &arr, vl &mask) {
    for (ll i=0;i<6;i++) if (arr[mask[i]][0] != arr[mask[(i+1)%6]][2]) return false;
    return true;
}

ll score(vector<array<ll, 3>> &arr, vl &mask) {
    ll sum=0;
    for (ll i=0;i<6;i++) sum+=arr[mask[i]][1];
    return sum;
}

void rotate(array<ll, 3> &t) {
    swap(t[0], t[1]);
    swap(t[2], t[1]);
}

void solve(ll testcase) {
    ll i, j;
    while (true) {
        ll n, s, t; cin>>n;
        if (!n) break;
        cin>>s>>t;
        vl arr(n); cin>>arr;
        if (t==1) {
            cout<<"0\n";
            continue;
        }
        vvl dp(n, vl(t-1, -INF));
        for (i=0;i<s;i++) dp[i][0] = arr[i];
        for (i=0;i<n;i++) {
            for (j=1;j<t-1;j++) {
                for (ll k=1;k<=s;k++)
                    if (i-k>=0) dp[i][j] = max(dp[i][j], dp[i-k][j-1]+arr[i]);
            }
        }
        // for (auto &x: dp) {
        //     for (auto &y: x)
        //         if (y<-1e9) cout<<"-I ";
        //         else cout<<y<<' ';
        //     cout<<endl;
        // }
        ll ans=dp[n-1][t-2];
        for (i=n-s;i<n-1;i++) ans=max(ans, dp[i][t-2]);
        cout<<ans<<endl;
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