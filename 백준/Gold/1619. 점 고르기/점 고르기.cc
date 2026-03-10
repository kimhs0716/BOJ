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

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vp arr(n);
    for (auto &[x, y] : arr) cin>>x>>y;
    ll ans = -1;
    for (i=0;i<n;i++) {
        map<pll, ll> slope;
        auto [x, y] = arr[i];
        for (j=0;j<i;j++) {
            auto [xx, yy] = arr[j];
            xx -= x;
            yy -= y;
            ll g = gcd(llabs(xx), llabs(yy));
            xx /= g; yy /= g;
            if (xx<0) {
                xx = -xx;
                yy = -yy;
            }
            slope[{xx, yy}]++;
        }
        for (auto [s, cnt] : slope) {
            if (cnt >= 2) ans = max(ans, cnt+1);
        }
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
