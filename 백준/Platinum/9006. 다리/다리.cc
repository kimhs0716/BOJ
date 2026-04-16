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

void solve(ll testcase) {
    ll i, j;
    ll n, m; cin>>n>>m;
    vl p(n), q(m), cand(n+m);
    cin>>p>>q;
    for (i=0;i<n;i++) cand[i]=p[i];
    for (i=0;i<m;i++) cand[n+i]=q[i];
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    sort(cand.rbegin(), cand.rend());
    // cand.erase(unique(cand.begin(), cand.end()), cand.end());
    ll t=-1;
    ll a=0, b=0, c=n, d=m;
    for (i=0;i<n+m;i++) {
        t=cand[i];
        // cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<t<<endl;
        if (p[a]==t) a++, c--;
        if (q[b]==t) b++, d--;
        if (a*b > c*d) break;
    }
    cout<<t<<".0\n";
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