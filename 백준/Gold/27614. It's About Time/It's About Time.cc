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
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

using numbers::pi;
void solve(ll testcase) {
    ll i, j, k;
    ld r, s, h; cin>>r>>s>>h;
    ld d = r * 2 * pi / (s * h);
    d = abs(d-lround(d));
    // cout<<fixed; cout.precision(10);
    // cout<<d<<endl;
    array<ll, 3> ans = {-1, -1, -1};
    ld min_diff = 1e10;
    for (j=2;j<=1000;j++) {
        for (k=j<<1;k<=1000;k+=j) {
            for (i=2;i<j;i++) {
                if (j%i==0) {
                    ld t = 1.0L/i - 1.0L/j + 1.0L/k;
                    ld diff = abs(d-t);
                    if (min_diff > diff) {
                        min_diff = diff;
                        ans = {i, j, k};
                    }
                }
            }
        }
    }
    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
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