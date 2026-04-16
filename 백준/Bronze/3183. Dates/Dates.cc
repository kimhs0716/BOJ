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
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
// constexpr ll MAX = 10'000'000;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll d, m, y;
    while (cin>>d>>m>>y) {
        if (!y) break;
        bool ans=true;
        if (m<1 || m>12) {
            ans=false;
        }
        else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
            if (d<1 || d>31) ans=false;
        }
        else if (m==2) {
            if (d<1 || d>29) ans=false;
            if (d==29) {
                if (y%4 || (y%100==0 && y%400)) ans=false;
            }
        }
        else {
            if (d<1 || d>30) ans=false;
        }
        if (ans) cout<<"Valid\n";
        else cout<<"Invalid\n";
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