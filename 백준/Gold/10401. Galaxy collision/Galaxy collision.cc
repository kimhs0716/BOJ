#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using vd = vector<ld>;
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
ostream& operator<<(ostream &os, vector<T> arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    map<pll, ll> pm;
    for (i=0;i<n;i++) {
        ll x, y; cin>>x>>y;
        pm[{x, y}] = i;
    }
    vvl adj(n);
    for (auto &[p, idx] : pm) {
        for (ll dx=-5;dx<=5;dx++)
            for (ll dy=-5;dy<=5;dy++) {
                if (dx*dx + dy*dy > 25) continue;
                if (dx==0 && dy==0) continue;
                ll nx = p.first+dx;
                ll ny = p.second+dy;
                if (pm.contains({nx, ny})) {
                    ll v = pm[{nx, ny}];
                    adj[idx].push_back(v);
                }
            }
    }
    // for (i=0;i<n;i++) {
    //     for (auto x: adj[i]) cout<<x<<' ';
    //     cout<<endl;
    // }
    vl vis(n);
    function<pll(ll, ll)> f = [&vis, &adj, &f](ll cur, ll c) -> pll{
        ll a=0, b=0;
        if (c) b++;
        else a++;
        for (ll nxt: adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = 1;
            auto [ta, tb] = f(nxt, !c);
            a += ta;
            b += tb;
        }
        return {a, b};
    };
    ll ans = 0;
    for (i=0;i<n;i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        auto [a, b] = f(i, 0);
        // cout<<i<<": "<<a<<' '<<b<<endl;
        ans += min(a, b);
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

