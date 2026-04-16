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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    map<ll, ll> cnt;
    while (n--) {
        ll x; cin>>x;
        cnt[x]++;
    }
    map<ll, set<ll>> m;
    for (i=1;i<=1000;i++) m[cnt[i]].insert(i);
    if (m.rbegin()->second.size() >= 2) {
        cout<<*m.rbegin()->second.rbegin()-*m.rbegin()->second.begin()<<endl;
    }
    else {
        ll ans = abs(*m.rbegin()->second.begin()-*next(m.rbegin())->second.rbegin());
        ans = max(ans, abs(*m.rbegin()->second.begin()-*next(m.rbegin())->second.begin()));
        cout<<ans<<endl;
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