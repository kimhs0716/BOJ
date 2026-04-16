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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
// constexpr ll MAX = 65536;

void preprocess() {
    ll i, j, k;
}

using KEY = array<ll, 4>;
void solve(ll testcase) {
    ll i, j, k;
    map<KEY, ll> cache;
    function<ll(ll, ll, ll, ll)> game = [&](ll a, ll b, ll c, ll turn) -> ll {
        if (a>b) swap(a, b);
        if (b>c) swap(b, c);
        if (a>b) swap(a, b);
        if (cache.contains({a, b, c, turn})) return cache[{a, b, c, turn}];
        ll &ret = cache[{a, b, c, turn}];
        if (!c) return ret = 0;
        if (turn&1) {
            ll get = min(c, turn);
            ret = game(a, b, c-get, turn+1) + get;
            get = min(b, turn);
            if (b) ret = max(ret, game(a, b-get, c, turn+1) + get);
            get = min(a, turn);
            if (a) ret = max(ret, game(a-get, b, c, turn+1) + get);
        }
        else {
            ll get = min(c, turn);
            ret = game(a, b, c-get, turn+1) - get;
            get = min(b, turn);
            if (b) ret = min(ret, game(a, b-get, c, turn+1) - get);
            get = min(a, turn);
            if (a) ret = min(ret, game(a-get, b, c, turn+1) - get);
        }
        return ret;
    };
    ll a, b, c; cin>>a>>b>>c;
    ll res = game(a, b, c, 1);
    if (res>0) cout<<'F';
    else if (res<0) cout<<'S';
    else cout<<'D';
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

