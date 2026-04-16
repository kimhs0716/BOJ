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

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
constexpr ll MAX = 1'000'000;

void preprocess() {
    ll i, j, k;
}

ll count(vl &arr, ll x) {
    return lower_bound(arr.begin(), arr.end(), x+1) - arr.begin();
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n>>k;
    vl a(n), b(n); cin>>a>>b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll lo=a[0]*b[0], hi=a.back()*b.back();
    // for (i=lo;i<=hi;i++) {
    //     ll cur = 0;
    //     for (j=0;j<n;j++) {
    //         cur += count(a, i/b[j]);
    //     }
    //     cout<<i<<' '<<cur<<endl;
    // }
    // return;
    while (lo<hi) {
        // cout<<lo<<' '<<hi<<endl;
        ll mid=(lo+hi)>>1;
        ll cur = 0;
        for (i=0;i<n;i++) {
            cur += count(a, mid/b[i]);
        }
        if (cur<k) lo=mid;
        else hi=mid;
        if (lo+1==hi) break;
    }
    ll cur = 0;
    for (j=0;j<n;j++) {
        cur += count(a, lo/b[j]);
    }
    if (cur==k) cout<<lo<<endl;
    else cout<<hi<<endl;
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