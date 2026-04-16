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

pair<vl, vl> f(vl &arr, vl& cost) {
    ll n = arr.size();
    vl left(n), right(n);
    right[0] = arr[0]+cost[0];
    for (ll i=1;i<n;i++) right[i] = max(right[i-1], cost[i]) + arr[i];
    left[n-1] = arr[n-1]+cost[n-1];
    for (ll i=n-2;i>=0;i--) left[i] = max(left[i+1], cost[i]) + arr[i];
    return {left, right};
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vl arr(m); cin>>arr;
    vl cost(m);
    cost[0] = arr[0];
    for (i=1;i<m;i++) cost[i] = cost[i-1]+arr[i];
    for (i=1;i<n-1;i++) {
        vl arr(m); cin>>arr;
        auto [left, right] = f(arr, cost);
        for (j=0;j<m;j++) cost[j] = max(left[j], right[j]);
        // cout<<left<<endl;
        // cout<<right<<endl;
        // cout<<cost<<endl<<endl;
    }
    if (n>=2) {
        cin>>arr;
        vl right(m);
        right[0] = cost[0]+arr[0];
        for (i=1;i<m;i++) right[i] = max(right[i-1], cost[i]) + arr[i];
        cost = right;
    }
    cout<<cost[m-1]<<endl;
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