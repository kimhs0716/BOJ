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
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n, p; cin>>n>>p;
    vp arr(n);
    for (i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    ll a=-1, b=-1;
    ld min_diff = INF;
    for (i=0;i<n;i++) {
        ll x = arr[i].first;
        ll pos = lower_bound(arr.begin(), arr.end(), make_pair<ll, ll>(p*x, -1)) - arr.begin();
        for (j=0;j<=2;j++) {
            if (pos-j>=0 && pos-j!=i) {
                ll y = arr[pos-j].first;
                ld diff = fabsl((ld)y/x-p);
                if (diff<min_diff) {
                    min_diff = diff;
                    a=i;
                    b=pos-j;
                }
            }
            if (pos+j<n && pos+j!=i) {
                ll y = arr[pos+j].first;
                ld diff = fabsl((ld)y/x-p);
                if (diff<min_diff) {
                    min_diff = diff;
                    a=i;
                    b=pos+j;
                }
            }
        }
    }
    cout<<arr[b].second<<' '<<arr[a].second<<endl;
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
