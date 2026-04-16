#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;

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

void solve(ll tc){
    ll i, j;
    ll a, b, c; cin>>a>>b>>c;
    ll x, n0; cin>>x>>n0;
    a -= x;
    ll D = b*b - 4*a*c;
    bool flag=false;
    if (a==0) {
        if (b>=0) flag=(b*n0+c>=0);
    }
    else if (a<0);
    else if (D<=0 || a*n0*n0 + b*n0 + c >= 0 && -b<=2*a*n0) flag=true;
    cout<<flag<<endl;
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