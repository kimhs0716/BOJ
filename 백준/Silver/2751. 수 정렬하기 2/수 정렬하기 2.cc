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
// constexpr ll MAX = 65536;

void preprocess() {
    ll i, j, k;
}

ll partition(vl &arr, ll lo, ll hi) {
    ll pivot = arr[lo];
    ll idx=lo+1, right=hi;
    while (idx<=right) {
        if (arr[idx]>pivot) swap(arr[idx], arr[right--]);
        else idx++;
    }
    swap(arr[lo], arr[idx-1]);
    return idx-1;
}

void quicksort(vl &arr, ll lo, ll hi) {
    if (lo>=hi) return;
    ll p = partition(arr, lo, hi);
    quicksort(arr, lo, p-1);
    quicksort(arr, p+1, hi);
}

static mt19937_64 rng(random_device{}());

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    shuffle(arr.begin(), arr.end(), rng);
    quicksort(arr, 0, n-1);
    for (auto x: arr) cout<<x<<endl;
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