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
    ll n, m, p; cin>>n>>m>>p;
    vector<string> name(n);
    vector<priority_queue<ll, vl, greater<>>> pq(n);
    vl used(n);
    for (i=0;i<n;i++) {
        cin>>name[i];
        for (j=0;j<m;j++) {
            ll x; cin>>x;
            pq[i].push(x);
        }
    }
    ll cnt=0;
    while (cnt<n) {
        ll mn = INF, idx = -1;
        for (j=0;j<n;j++) {
            if (used[j]) continue;
            if (pq[j].top() < mn || (pq[j].top()==mn && name[j]<name[idx])) {
                mn = pq[j].top();
                idx = j;
            }
        }
        for (j=0;j<n;j++) {
            if (used[j]) continue;
            ll x = pq[j].top();
            pq[j].pop();
            if (j!=idx) pq[j].push(x+p);
            if (pq[j].empty()) {
                cout<<name[j]<<' ';
                used[j] = 1;
                cnt++;
            }
        }
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

