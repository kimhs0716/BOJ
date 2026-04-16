#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
// using ll = long long;
using ll = int;
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
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
// constexpr ll INF = 2e18;
constexpr ll MAX = 1'000'000;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll a, b; cin>>a>>b;
    set<pair<ll, bool>> s;
    queue<tlll> q;
    q.push({a, 0, 0});
    s.insert({a, 0});
    while (q.size()) {
        // cout<<q.size()<<endl;
        auto [cur, time, used] = q.front();
        q.pop();
        ll nxt;

        nxt = cur+1;
        if (nxt==b) {
            cout<<time+1<<endl;
            return;
        }
        if (nxt<b && !s.contains({nxt, used})) {
            q.push({nxt, time+1, used});
            s.insert({nxt, used});
        }

        nxt = cur<<1;
        if (nxt==b) {
            cout<<time+1<<endl;
            return;
        }
        if (nxt<b && !s.contains({nxt, used})) {
            q.push({nxt, time+1, used});
            s.insert({nxt, used});
        }

        if (used==0) {
            nxt = cur*10;
            if (nxt==b) {
                cout<<time+1<<endl;
                return;
            }
            if (nxt<b && !s.contains({nxt, 1})) {
                q.push({nxt, time+1, 1});
                s.insert({nxt, 1});
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