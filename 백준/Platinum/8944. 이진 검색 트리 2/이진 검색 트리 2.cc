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
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 9'999'991;
// constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
constexpr ll MAX = 1'000'000;

void preprocess() {
    ll i, j, k;
}

vvl cache(25, vl(25));
ll comb(ll n, ll m) {
    ll &ret = cache[n][m];
    if (!ret) {
        if (m==0 || m==n) return 1;
        ret = (comb(n-1, m-1) + comb(n-1, m))%MOD;
    }
    return ret;
}

ll f(vl &arr) {
    ll n=arr.size();
    if (n<=2) return 1;
    ll pivot = arr[0];
    vl left, right;
    for (ll i=1;i<n;i++) {
        if (arr[i]<pivot) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    ll fl = f(left);
    ll fr = f(right);
    return fl*fr%MOD*comb(n-1, left.size())%MOD;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    cout<<f(arr)<<endl;
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