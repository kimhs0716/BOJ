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
constexpr ll INF = (ll)1e18+1;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vvl arr(n, vl(n)); cin>>arr;
    function check = [](vl &a) {
        ll ret = -INF, n = a.size();
        for (ll i=0;i<n;i++) a.push_back(a[i]);
        for (ll i=0;i<n;i++) {
            ll sum = 0;
            for (ll j=0;j<n;j++) {
                if (i+j>=2*n) break;
                sum += a[i+j];
                ret = max(ret, sum);
            }
        }
        for (ll i=0;i<n;i++) a.pop_back();
        return ret;
    };
    ll ans = -INF;
    for (i=0;i<n;i++) {
        ans = max(ans, check(arr[i]));
        // cout<<arr[i]<<": ";
        // cout<<check(arr[i])<<endl;
    }
    for (i=0;i<n;i++) {
        vl t(n);
        for (j=0;j<n;j++) t[j] = arr[j][i];
        ans = max(ans, check(t));
        // cout<<t<<": "<<check(t)<<endl;
    }
    for (i=0;i<n;i++) {
        vl t(n);
        ll r=i, c=0;
        for (j=0;j<n;j++) {
            t[j] = arr[r][c];
            r = (r+1)%n;
            c = (c+1)%n;
        }
        ans = max(ans, check(t));
        // cout<<t<<": "<<check(t)<<endl;
    }
    for (i=0;i<n;i++) {
        vl t(n);
        ll r=i, c=0;
        for (j=0;j<n;j++) {
            t[j] = arr[r][c];
            r = (r+1)%n;
            c = (c+n-1)%n;
        }
        ans = max(ans, check(t));
        // cout<<t<<": "<<check(t)<<endl;
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
