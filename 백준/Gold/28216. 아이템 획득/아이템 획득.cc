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

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, q; cin>>n>>q;
    map<pll, ll> box;
    map<ll, vp> xm, ym;
    for (i=0;i<n;i++) {
        ll x, y, w; cin>>x>>y>>w;
        box[{x, y}] = w;
        xm[x].push_back({y, w});
        ym[y].push_back({x, w});
    }
    map<ll, array<vl, 2>> xv, yv;
    for (auto &[x, arr] : xm) {
        sort(arr.begin(), arr.end());
        ll s = 0;
        xv[x][0].push_back(0);
        xv[x][1].push_back(0);
        for (auto &[y, w] : arr) {
            xv[x][0].push_back(y);
            s += w;
            xv[x][1].push_back(s);
        }
        xv[x][1].push_back(s);
        xv[x][0].push_back(INF);
    }
    for (auto &[y, arr] : ym) {
        sort(arr.begin(), arr.end());
        ll s = 0;
        yv[y][0].push_back(0);
        yv[y][1].push_back(0);
        for (auto &[x, w] : arr) {
            yv[y][0].push_back(x);
            s += w;
            yv[y][1].push_back(s);
        }
        yv[y][1].push_back(s);
        yv[y][0].push_back(INF);
    }
    ll x=1, y=1;
    ll ans=0;
    while (q--) {
        ll d, v; cin >> d >> v;

        if (d == 0) {
            vl &arr = yv[y][0];
            ll lo = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
            x += v;
            ll hi = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
            if (arr.empty()) continue;
            ll s1 = (lo ? yv[y][1][lo - 1] : 0);
            ll s2 = (hi ? yv[y][1][hi - 1] : 0);
            ans += s2 - s1;
        }
        else if (d == 1) {
            vl &arr = xv[x][0];
            ll lo = upper_bound(arr.begin(), arr.end(), y) - arr.begin();
            y += v;
            ll hi = upper_bound(arr.begin(), arr.end(), y) - arr.begin();
            if (arr.empty()) continue;
            ll s1 = (lo ? xv[x][1][lo - 1] : 0);
            ll s2 = (hi ? xv[x][1][hi - 1] : 0);
            ans += s2 - s1;
        }
        else if (d == 2) {
            vl &arr = yv[y][0];
            ll hi = upper_bound(arr.begin(), arr.end(), x - 1) - arr.begin();
            x -= v;
            ll lo = upper_bound(arr.begin(), arr.end(), x - 1) - arr.begin();
            if (arr.empty()) continue;
            ll s1 = (hi ? yv[y][1][hi - 1] : 0);
            ll s2 = (lo ? yv[y][1][lo - 1] : 0);
            ans += s1 - s2;
        }
        else {
            vl &arr = xv[x][0];
            ll hi = upper_bound(arr.begin(), arr.end(), y - 1) - arr.begin();
            y -= v;
            ll lo = upper_bound(arr.begin(), arr.end(), y - 1) - arr.begin();
            if (arr.empty()) continue;
            ll s1 = (hi ? xv[x][1][hi - 1] : 0);
            ll s2 = (lo ? xv[x][1][lo - 1] : 0);
            ans += s1 - s2;
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