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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n, c; cin>>n>>c;
    vl arr(n); cin>>arr;
    ll a=n/2, b=n-a;
    vl left, right;
    for (i=0;i<(1<<a);i++) {
        ll s = 0;
        for (j=0;j<a;j++) {
            if ((i>>j)&1) s += arr[j];
        }
        left.push_back(s);
    }
    for (i=0;i<(1<<b);i++) {
        ll s = 0;
        for (j=0;j<b;j++) {
            if ((i>>j)&1) s += arr[a+j];
        }
        right.push_back(s);
    }
    ll ans = 0;
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (auto x: left) {
        if (x>c) continue;
        ll idx = upper_bound(right.begin(), right.end(), c-x) - right.begin();
        ans += idx;
    }
    // cout<<left<<endl;
    // cout<<right<<endl;
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
