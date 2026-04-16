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
constexpr ll INF = 1e18;
constexpr ll MAX = 100'000;

void preprocess() {
    ll i, j, k;
}

ll index(vl &arr, ll s, ll tar) {
    ll i;
    for (i=s;i<arr.size();i++)
        if (arr[i]==tar) break;
    return i;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n>>k;
    vl arr(k); cin>>arr;
    ll ans=0;
    set<ll> use;
    for (i=0;i<k;i++) {
        if (use.size()<n || use.contains(arr[i])) use.insert(arr[i]);
        else {
            ll m = 0, tar = -1;
            for (auto x: use) {
                ll t = index(arr, i+1, x);
                if (t>m) m=t, tar=x;
            }
            use.erase(tar);
            use.insert(arr[i]);
            ans++;
        }
        // cout<<i<<": ";
        // for (auto x: use) cout<<x<<' '; cout<<endl;
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

