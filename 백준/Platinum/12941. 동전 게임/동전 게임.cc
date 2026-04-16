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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

map<ll, char> cache;
char g(ll x) {
    if (cache.contains(x)) return cache[x];
    if (x==0) return 0;
    if (x==1) return 1;
    if (x==2) return 0;
    if (x==3) return 1;
    if (x==4) return 2;
    if (x&1) return cache[x] = 0;
    if (g(x>>1)==1) return cache[x] = 2;
    return cache[x] = 1;
}

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n>>k;
    ll s = 0;
    if (k&1) {
        while (n--) {
            ll x; cin>>x;
            s ^= g(x);
        }
    }
    else {
        while (n--) {
            ll x; cin>>x;
            if (x==1) s^=1;
            else if (x==2) s^=2;
            else if (x%2==0) s^=1;
        }
    }
    cout<<(s ? "Kevin" : "Nicky")<<endl;
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