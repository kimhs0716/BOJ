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
    map<ll, ll> cnt;
    while (n--) {
        ll x; cin>>x;
        cnt[x]++;
    }
    vp arr;
    for (auto it=cnt.rbegin(); it!=cnt.rend(); it++) {
        ll a=it->first, b=it->second;
        if (cnt[a+1] && b) {
            arr.push_back({a, 1});
            cnt[a]--;
        }
        if (cnt[a]>=2) {
            arr.push_back({a, cnt[a]>>1});
            cnt[a] %= 2;
        }
    }
    ll ans = 0;
    for (i=0;i<arr.size();i++) {
        if (i!=0 && arr[i].second && arr[i-1].second) {
            arr[i].second--;
            ans += arr[i].first * arr[i-1].first;
        }
        ans += arr[i].first * arr[i].first * (arr[i].second/2);
        arr[i].second %= 2;
    }
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

