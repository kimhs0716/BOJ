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

vl factorize(ll n) {
    vl ret;
    for (ll i=2; i*i<=n; i++) {
        while (n%i==0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n!=1) ret.push_back(n);
    return ret;
}

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    vl fib {0, 1};
    while (fib.back()<=1e18) {
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }
    fib.pop_back();
    vl ans;
    ll n; cin>>n;
    for (i=fib.size()-1;i>1;i--) {
        if (n>=fib[i]) {
            n -= fib[i];
            ans.push_back(1);
        }
        else ans.push_back(0);
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() && ans.back()==0) ans.pop_back();
    if (ans.empty()) ans.push_back(0);
    reverse(ans.begin(), ans.end());
    for (auto x: ans) cout<<x; cout<<endl;
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
