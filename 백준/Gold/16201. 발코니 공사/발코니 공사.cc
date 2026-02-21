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

ll modpow(ll n, ll k) {
    ll ret = 1;
    while (k) {
        if (k&1) ret = ret*n%MOD;
        n = n*n%MOD;
        k >>= 1;
    }
    return ret;
}

void solve(ll tc){
    ll i, j;
    ll r, c, m; cin>>r>>c>>m;
    ll ans = 1, cnt = 0;
    map<ll, vl> b;
    while (m--) {
        ll x, y; cin>>x>>y;
        b[x].push_back(y);
    }
    for (auto &[x, vy] : b)
        sort(vy.begin(), vy.end());
    ans = ((c&1) ? modpow(c/2+1, r) : 1);
    cnt = r*(c/2);
    for (auto &[x, vy] : b) {
        cnt -= c/2;
        if (c&1) ans = ans * modpow(c/2+1, MOD-2) % MOD;
        ll p = 1;
        vy.push_back(c+1);
        for (auto y: vy) {
            // cout<<p<<' '<<y<<endl;
            if (y-p >= 2) {
                cnt += (y-p)/2;
                if ((y-p)&1) {
                    ans = ans * ((y-p)/2+1) % MOD;
                }
            }
            p = y+1;
        }
    }
    cout<<cnt<<' '<<ans<<endl;
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
