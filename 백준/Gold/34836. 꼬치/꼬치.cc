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
    vl arr(n); cin>>arr;
    vl pre_max(n+1);
    pre_max[0] = 0;
    for (i=1;i<=n;i++)
        pre_max[i] = max(pre_max[i-1], arr[i-1]);
    vl suf_min(n+1);
    suf_min[n] = INF;
    for (i=n-1;i>=0;i--)
        suf_min[i] = min(suf_min[i+1], arr[i]);

    vl left(n), right(n);
    for (i=0;i<n;i++) {
        if (pre_max[i] < arr[i]) left[i] = 1;
        if (suf_min[i+1] > arr[i]) right[i] = 1;
    }
    ll ans = 0;
    ll s = 0;
    while (s < n) {
        ll e = s;
        while (e+1<n && arr[e+1]==arr[e]+1) e++;
        ll ls = n+1;
        ll re = -1;
        for (i=s; i<=e; i++) {
            if (left[i] && ls>n) ls = i;
            if (right[i]) re = i;
        }
        if (ls <= re) {
            ll len = re - ls + 1;
            ans = max(ans, len);
        }
        s = e+1;
    }
    cout<<2*(n-ans)<<endl;
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

