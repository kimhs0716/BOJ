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

void setup() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

void solve(ll tc) {
    ll i, j, k;
    ll d, p, q;
    cin>>d>>p>>q;
    if (p<q) swap(p, q);
    ll ans=INF;
    ll max_val = min((d+p-1)/p, q-1);
    for (ll x=0;x<=max_val;x++) {
        ll y=(d-p*x+q-1)/q;
        ll tmp = p*x+q*y;
        ans=min(tmp, ans);
    }
    cout<<ans<<endl;
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