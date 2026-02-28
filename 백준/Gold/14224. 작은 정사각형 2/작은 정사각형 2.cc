#include <bits/stdc++.h>

#include <utility>
#pragma GCC optimize ("O0,unroll-loops")
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

ll check(vp &arr, ll x, ll y, ll d) {
    ll ret = 0;
    for (auto [xx, yy] : arr) {
        if (!(x<xx && xx<x+d)) continue;
        if (!(y<yy && yy<y+d)) continue;
        ret++;
    }
    return ret;
}

void solve(ll tc){
    ll i, j;
    ll n, k; cin>>n>>k;
    vp arr(n);
    set<ll> sx, sy;
    for (auto &[x, y] : arr) {
        cin>>x>>y;
        sx.insert(x);
        sy.insert(y);
    }

    ll ans = INF;
    for (auto x : sx) {
        for (auto y : sy) {
            ll lo=0, hi=INF;
            if (check(arr, x-1, y-1, hi) < k) continue;
            while (lo+1<hi) {
                ll m = (lo+hi)>>1;
                if (check(arr, x-1, y-1, m) >= k) hi = m;
                else lo = m;
            }
            ans = min(ans, hi);
        }
    }
    cout<<ans*ans<<endl;
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
