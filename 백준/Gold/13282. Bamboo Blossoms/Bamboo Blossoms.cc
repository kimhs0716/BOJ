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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

constexpr ll MAX=7500000;

void solve(ll tc){
    ll i, j;
    while (true) {
        ll m, n; cin>>m>>n;
        if (!m) break;
        vector<bool> arr(MAX);
        for (i=m;i<MAX;i++) {
            if (arr[i]==0) n--;
            else continue;
            if (n==-1) {
                cout<<i<<endl;
                break;
            }
            for (j=i<<1;j<MAX;j+=i) {
                arr[j]=1;
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