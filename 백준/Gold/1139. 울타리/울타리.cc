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

ld area(ll a, ll b, ll c) {
    ll sum=a+b+c, mv=max({a, b, c});
    if (sum-mv<=mv) return -1;
    ld s = ((ld)a+b+c)/2;
    return sqrtl(s*(s-a)*(s-b)*(s-c));
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    vd dp(1<<n, -1);
    function<ld(ll)> f = [&dp, &arr, &f, n](ll bm) {
        ld &ret = dp[bm];
        if (ret != -1) return ret;
        ret = 0;
        for (ll i=0;i<n;i++) {
            if ((bm>>i)&1) continue;
            bm ^= 1<<i;
            for (ll j=i+1;j<n;j++) {
                if ((bm>>j)&1) continue;
                bm ^= 1<<j;
                for (ll k=j+1;k<n;k++) {
                    if ((bm>>k)&1) continue;
                    bm ^= 1<<k;
                    ret = max(ret, area(arr[i], arr[j], arr[k]) + f(bm));
                    bm ^= 1<<k;
                }
                bm ^= 1<<j;
            }
            bm ^= 1<<i;
        }
        return ret;
    };
    cout<<fixed<<setprecision(12);
    cout<<f(0)<<endl;
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

