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
    ll n, k; cin>>n>>k;
    vl cost(n); cin>>cost;
    vl psum1(n+1), psum2(n+1);
    sort(cost.begin(), cost.end());
    for (i=1;i<=n;i++) psum1[i] = psum1[i-1] + cost[i-1];
    reverse(cost.begin(), cost.end());
    for (i=1;i<=n;i++) psum2[i] = psum2[i-1] + cost[i-1];
    // cout<<psum1<<endl;
    // cout<<psum2<<endl;
    vp arr;
    for (i=0;i<k;i++) {
        ll a, b; cin>>a>>b;
        arr.push_back({a, 0});
        arr.push_back({b+1, 1});
    }
    sort(arr.begin(), arr.end());
    ll cnt = 0, ans1 = 0, ans2 = 0;
    ll prev = arr[0].first;
    for (auto [a, b] : arr) {
        // cout<<prev<<' '<<a<<' '<<b<<' '<<cnt<<endl;
        ans1 += (a-prev) * psum1[cnt];
        ans2 += (a-prev) * psum2[cnt];
        if (!b) cnt++;
        else cnt--;
        prev = a;
    }
    cout<<ans1<<' '<<ans2<<endl;
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

