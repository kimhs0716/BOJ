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

vl dp(MAX+1, INF);

ll f(ll n, vl &arr) {
    ll &ret = dp[n];
    ll t=n;
    bool flag = true;
    while (t) {
        if (!arr[t%10]) {
            flag = false;
            break;
        }
        t /= 10;
    }
    if (flag) return ret=0;
    if (ret!=INF) return ret;
    for (ll i=2;i*i<=n;i++) {
        if (n%i) continue;
        ll r1 = f(i, arr), r2 = f(n/i, arr);
        if (r1!=-1 && r2!=-1) ret = min(ret, r1+r2+1);
    }
    if (ret==INF) ret=-1;
    return ret;
}

void solve(ll testcase) {
    ll i, j, k;
    dp.assign(MAX+1, INF);
    ll n; cin>>n;
    vl arr(10);
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        arr[x]=1;
    }
    ll q; cin>>q;
    while (q--) {
        ll x; cin>>x;
        cout<<f(x, arr)<<endl;
    }
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