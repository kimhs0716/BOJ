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
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

void f(vl &arr) {
    ll n = arr.size();
    ll cnt=0;
    for (ll i=0;i<n;i++) {
        if (arr[i]=='a') {
            arr[i]='.';
            cnt++;
        }
        else if (arr[i]=='#') {
            for (ll j=0;j<cnt;j++) {
                arr[i-j-1]='a';
            }
            cnt=0;
        }
    }
    for (ll i=0;i<cnt;i++) arr[n-i-1]='a';
}

void solve(ll testcase) {
    ll i, j, k;
    ll r, c; cin>>r>>c;
    vvl arr(c, vl(r));
    for (i=0;i<r;i++) {
        string s; cin>>s;
        for (j=0;j<c;j++) arr[j][i] = s[j];
    }
    for (auto &a: arr) f(a);
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) {
            cout<<(char)arr[j][i];
        }
        cout<<endl;
    }
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