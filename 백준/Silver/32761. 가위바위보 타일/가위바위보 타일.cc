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
    // cout<<is_prime(999998765536093)<<endl;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    string s; cin>>s;
    ll max_val = 0;
    char target = 'S';
    ll t = 0;
    for (i=0;i<n;i++) {
        if (s[i] == target) {
            t++;
            if (target=='S') target='P';
            else if (target=='P') target='R';
            else target='S';
        }
    }
    t-=t%3;
    max_val = max(max_val, t);
    target='R';
    t = 0;
    for (i=0;i<n;i++) {
        if (s[i] == target) {
            t++;
            if (target=='S') target='P';
            else if (target=='P') target='R';
            else target='S';
        }
    }
    t-=t%3;
    max_val = max(max_val, t);
    target='P';
    t = 0;
    for (i=0;i<n;i++) {
        if (s[i] == target) {
            t++;
            if (target=='S') target='P';
            else if (target=='P') target='R';
            else target='S';
        }
    }
    t-=t%3;
    max_val = max(max_val, t);
    cout<<n-max_val<<endl;
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