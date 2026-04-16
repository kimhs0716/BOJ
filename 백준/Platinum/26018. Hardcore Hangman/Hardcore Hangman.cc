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

void preprocess() {
    ll i, j;

}

void solve(ll testcase) {
    ll i, j, k;
    cout<<"? ";
    for (i=0;i<26;i++) cout<<(char)(i+'a');
    cout<<endl<<flush;
    ll n; cin>>n;
    for (i=0;i<n;i++) {
        ll x; cin>>x;
    }
    vl ans(n);
    for (i=0;i<=4;i++) {
        cout<<"? ";
        for (j=0;j<26;j++) {
            if ((j>>i)&1) cout<<(char)(j+'a');
        }
        cout<<endl<<flush;
        ll res; cin>>res;
        for (j=0;j<res;j++) {
            ll x; cin>>x;
            ans[x-1] |= (1<<i);
        }
    }
    cout<<"! ";
    for (auto x: ans) cout<<(char)(x+'a');
    cout<<endl<<flush;
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