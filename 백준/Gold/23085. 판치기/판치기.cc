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

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n>>k;
    ll cnt = 0;
    string s; cin>>s;
    for (auto ch: s) if (ch=='H') cnt++;
    queue<ll> q;
    set<ll> vis;
    vis.insert(cnt);
    q.push(cnt);
    ll ans = 0;
    while (q.size()) {
        ll sz = q.size();
        while (sz--) {
            ll h = q.front(), t = n - h;
            if (h==0) {
                cout<<ans<<endl;
                return;
            }
            q.pop();
            for (i=max(0LL, k-t);i<=min(h, k);i++) {
                ll nxt = h - i + (k-i);
                if (vis.contains(nxt)) continue;
                vis.insert(nxt);
                q.push(nxt);
            }
        }
        ans++;
    }
    cout<<"-1\n";
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

