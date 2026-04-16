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
    ll i, j, k;
    ll n; cin>>n;
    vl pre(n), in(n);
    cin>>pre>>in;
    stack<ll> ans;
    function<void(ll, ll, ll, ll)> f = [&ans, &pre, &in, &n, &f](ll l1, ll r1, ll l2, ll r2) {
        ans.push(pre[l1]);
        if (l1==r1) return;
        ll t=0;
        while (in[t+l2]!=pre[l1]) t++;
        // cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<endl;
        if (l1+t<n-1 && l1+t+1<=r1 && l2+t+1<=r2) f(l1+t+1, r1, l2+t+1, r2);
        if (l1<n-1 && 1<=t) f(l1+1, l1+t, l2, l2+t-1);
    };
    f(0, n-1, 0, n-1);
    while (ans.size()) {
        cout<<ans.top()<<' ';
        ans.pop();
    }
    cout<<endl;
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