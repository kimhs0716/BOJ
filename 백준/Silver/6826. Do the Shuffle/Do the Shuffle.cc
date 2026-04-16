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
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j;
    deque<ll> dq {0, 1, 2, 3, 4};
    ll x, k;
    while (cin>>x>>k) {
        if (x==1) {
            for (i=0;i<k;i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else if (x==2) {
            for (i=0;i<k;i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else if (x==3) {
            if (k&1) {
                ll a = dq.front();
                dq.pop_front();
                ll b = dq.front();
                dq.pop_front();
                dq.push_front(a);
                dq.push_front(b);
            }
        }
        else {
            for (i=0;i<5;i++) {
                cout<<(char)('A'+dq.front())<<' ';
                dq.pop_front();
            }
            cout<<endl;
            return;
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