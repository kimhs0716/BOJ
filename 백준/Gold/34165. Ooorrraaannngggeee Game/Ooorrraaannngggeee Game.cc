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
using tllll = array<ll, 4>;

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
    ll i, j, k;
    string o = "orange";
    string s; cin>>s;
    ll n=s.size();
    vector<array<tllll, 6>> dp(n);
    for (i=0;i<n;i++) for (j=0;j<6;j++) dp[i][j] = {0, -1, 0, 0};
    if (s[0]=='o') dp[0][0] = {1, -1, 1, 1};
    for (i=1;i<n;i++) {
        for (j=0;j<6;j++) dp[i][j] = dp[i-1][j], dp[i][j][3] = 0, dp[i][j][2]=0;
        if (s[i]=='o') {
            dp[i][0] = {1, -1, 1, 1};
            if (dp[i-1][0][0] != 0) dp[i][0] = {dp[i-1][0][0]+1, i-1, 0, 1};
        }
        if (s[i]=='r') {
            if (dp[i-1][0][0] != 0) {
                dp[i][1] = {dp[i-1][0][0]+1, i-1, 1, 1};
            }
            if (dp[i-1][1][0] && dp[i-1][1][0]+1 > dp[i][1][0]) {
                dp[i][1] = {dp[i-1][1][0]+1, i-1, 0, 1};
            }
        }
        if (s[i]=='a') {
            if (dp[i-1][1][0] != 0) {
                dp[i][2] = {dp[i-1][1][0]+1, i-1, 1, 1};
            }
            if (dp[i-1][2][0] && dp[i-1][2][0]+1 > dp[i][2][0]) {
                dp[i][2] = {dp[i-1][2][0]+1, i-1, 0, 1};
            }
        }
        if (s[i]=='n') {
            if (dp[i-1][2][0] != 0) {
                dp[i][3] = {dp[i-1][2][0]+1, i-1, 1, 1};
            }
            if (dp[i-1][3][0] && dp[i-1][3][0]+1 > dp[i][3][0]) {
                dp[i][3] = {dp[i-1][3][0]+1, i-1, 0, 1};
            }
        }
        if (s[i]=='g') {
            if (dp[i-1][3][0] != 0) {
                dp[i][4] = {dp[i-1][3][0]+1, i-1, 1, 1};
            }
            if (dp[i-1][4][0] && dp[i-1][4][0]+1 > dp[i][4][0]) {
                dp[i][4] = {dp[i-1][4][0]+1, i-1, 0, 1};
            }
        }
        if (s[i]=='e') {
            if (dp[i-1][4][0] != 0) {
                dp[i][5] = {dp[i-1][4][0]+1, i-1, 1, 1};
            }
            if (dp[i-1][5][0] && dp[i-1][5][0]+1 > dp[i][5][0]) {
                dp[i][5] = {dp[i-1][5][0]+1, i-1, 0, 1};
            }
        }
    }
    // for (i=0;i<n;i++) {
    //     for (j=0;j<6;j++) {
    //         cout<<dp[i][j][0]<<dp[i][j][1]<<dp[i][j][2]<<dp[i][j][3]<<"|";
    //     }
    //     cout<<endl;
    // }
    if (dp[n-1][5][0]==0) {
        cout<<"0\n";
        return;
    }
    string ans;
    ll ch = 5;
    ll cur=n-1;
    while (ch!=-1 && cur!=-1) {
        // cout<<cur<<' '<<ch<<endl;
        if (dp[cur][ch][3]) ans.push_back(o[ch]);
        bool dec = dp[cur][ch][2];
        cur--;
        if (dec) ch--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
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