#include <bits/stdc++.h>

#include <utility>
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
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    ll a, b; cin>>a>>b;
    vl f(n+1), m(n+1);
    ll is_m = 0;
    for (i=1;i<=n;i++) {
        cin>>f[i]>>m[i];
        if (m[i]==b) is_m = 1;
    }
    vl ans(n+1, INF);
    ans[a] = 0;
    deque<ll> dq;
    dq.push_back(a);
    while (dq.size()) {
        ll cur = dq.front(); dq.pop_front();
        if (f[cur] && ans[cur] < ans[f[cur]]) {
            ans[f[cur]] = ans[cur];
            dq.push_front(f[cur]);
        }
        if (m[cur] && ans[cur]+1 < ans[m[cur]]) {
            ans[m[cur]] = ans[cur]+1;
            dq.push_back(m[cur]);
        }
    }
    if (ans[b]==INF) cout<<"no ancestor\n";
    else cout<<ans[b]-is_m<<endl;
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
