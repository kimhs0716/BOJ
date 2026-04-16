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

void solve(ll tc){
    ll i, j;
    ll t; cin>>t;
    ll p, q;
    char d;
    cin>>p>>d>>q;
    if (q==1) {
        q=p+1;
        p=1;
    }
    else if (p<q) {
        ll temp=q;
        q-=p;
        p=temp;
    }
    else {
        ll cnt=0;
        while (p>q) {
            cnt++;
            p-=q;
        }
        q-=p;
        p+=q;
        while (cnt--) q+=p;
    }
    cout<<t<<' '<<p<<'/'<<q<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}