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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ll MAX = 1'000'000;

vl primes;
void preprocess() {
    ll i, j, k;
    vl arr(MAX);
    arr[0] = arr[1] = 1;
    for (i=2;i<MAX;i++) {
        if (arr[i]) continue;
        primes.push_back(i);
        for (j=i<<1;j<MAX;j+=i)
            arr[j] = 1;
    }
    // for (i=0;i<10;i++) cout<<primes[i]<<endl;
}

void solve(ll testcase) {
    ll i, j, k;
    ll a, b; cin>>a>>b;
    ll left = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
    ll right = lower_bound(primes.begin(), primes.end(), b) - primes.begin();
    if (right==primes.size() || primes[right]>b) right--;
    if ((right+left)&1) cout<<"-1\n";
    else cout<<primes[(left+right)>>1]<<endl;
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

