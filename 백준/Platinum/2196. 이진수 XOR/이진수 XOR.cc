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

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll b, n; cin>>b>>n;
    ll tar = 0;
    string s; cin>>s;
    for (i=0;i<b;i++) {
        tar <<= 1;
        tar |= s[i]-'0';
    }
    vl arr(n);
    for (i=0;i<n;i++) {
        cin>>s;
        for (j=0;j<b;j++) {
            arr[i] <<= 1;
            arr[i] |= s[j]-'0';
        }
    }
    // cout<<tar<<endl;
    // cout<<arr<<endl;
    ll total = 1<<b;
    vl dp(total, INF), vis(total);
    queue<ll> q;
    for (ll x: arr) {
        q.push(x);
        dp[x] = 0;
    }
    ll d = 1;
    while (q.size()) {
        ll sz = q.size();
        while (sz--) {
            ll cur = q.front(); q.pop();
            for (ll x: arr) {
                if (dp[cur^x]==0 || dp[cur^x]==INF) {
                    if (dp[cur^x]==INF) q.push(cur^x);
                    dp[cur^x] = d;
                }
            }
        }
        d++;
    }
    ll ans = -1, diff = INF, steps = INF;
    for (i=0;i<total;i++) {
        if (dp[i]==INF) continue;
        ll cd = __builtin_popcountll(i^tar);
        if (cd < diff) {
            ans = i;
            diff = cd;
            steps = dp[i];
        }
        if (cd==diff && dp[i]<steps) {
            ans = i;
            steps = dp[i];
        }

    }
    cout<<steps<<endl;
    for (i=b-1;i>=0;i--) cout<<((ans>>i)&1);
    cout<<endl;
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
