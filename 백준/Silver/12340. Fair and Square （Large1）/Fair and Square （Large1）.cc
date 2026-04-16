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

bool is_pal(ll n) {
    ll a=n, b=0;
    while (a) {
        b *= 10;
        b += a%10;
        a /= 10;
    }
    return b==n;
}

vl arr = {0};
void preprocess() {
    ll i, j;
    for (i=1;i<=10'000'000;i++) {
        if (is_pal(i) && is_pal(i*i)) arr.push_back(i*i);
    }
    // cout<<arr.size()<<endl;
    // for (i=1;i<=39;i++) {
    //     cout<<i<<": "<<arr[i]<<endl;
    // }
}

void solve(ll testcase) {
    ll i, j, k;
    ll a, b; cin>>a>>b;
    cout<<"Case #"<<testcase<<": ";
    cout<<lower_bound(arr.begin(), arr.end(), b+1)-lower_bound(arr.begin(), arr.end(), a)<<endl;
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