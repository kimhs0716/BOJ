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
    ll n; cin>>n;
    vl arr(n*3);
    string s; cin>>s;
    for (i=0;i<3*n;i++) {
        if (s[i] == 'B') arr[i] = 0;
        if (s[i] == 'L') arr[i] = 1;
        if (s[i] == 'D') arr[i] = 2;
    }
    set<pll> vis;
    queue<pll> q;
    q.push({0, 3*n-1});
    ll time = 0;
    // cout<<arr<<endl;
    while (q.size()) {
        ll sz = q.size();
        // cout<<"=== "<<time<<" ===\n";
        while (sz--) {
            auto [l, r] = q.front(); q.pop();
            // cout<<l<<' '<<r<<endl;
            if (l>r) continue;
            ll tar = time%3;
            if (arr[l] == tar) {
                if (!vis.contains({l+1, r})) {
                    vis.insert({l+1, r});
                    q.push({l+1, r});
                }
            }
            if (arr[r] == tar) {
                if (!vis.contains({l, r-1})) {
                    vis.insert({l, r-1});
                    q.push({l, r-1});
                }
            }
        }
        time++;
    }
    cout<<time-1<<endl;
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

