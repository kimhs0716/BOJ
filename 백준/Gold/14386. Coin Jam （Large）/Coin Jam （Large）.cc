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

string bin(ll n) {
    string ret;
    while (n) {
        ret.push_back('0'+(n&1));
        n >>= 1;
    }
    reverse(ret.begin(), ret.end());
    if (ret.empty()) ret.push_back('0');
    return ret;
}

ll __pow(ll n, ll r) {
    ll ret = 1;
    while (r--) ret *= n;
    return ret;
}

void solve(ll tc) {
    ll i, j;
    cout<<"Case #"<<tc<<":"<<endl;
    ll n, m; cin>>n>>m;
    for (i=0;i<m;i++) {
        ll half = (1<<(n/2-1))|(i<<1)|1;
        string b = bin(half);
        cout<<b<<b<<' ';
        for (j=2;j<=10;j++) {
            cout<<__pow(j, n/2)+1<<' ';
        }
        cout<<endl;
    }
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
