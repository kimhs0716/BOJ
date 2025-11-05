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

ll check(vvl &arr, ll a, ll b) {
    ll i, n = arr.size();
    if (b==0) {
        ll ret = 0, prev = -1, cur = 0;
        for (i=0;i<n;i++) {
            if (arr[i][a] != prev) {
                prev = arr[i][a];
                cur = 0;
            }
            cur++;
            ret = max(ret, cur);
        }
        return ret;
    }
    ll ret = 0, prev = -1, cur = 0;
    for (i=0;i<n;i++) {
        if (arr[a][i] != prev) {
            prev = arr[a][i];
            cur = 0;
        }
        cur++;
        ret = max(ret, cur);
    }
    return ret;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vvl arr(n, vl(n));
    for (i=0;i<n;i++) {
        string s; cin>>s;
        for (j=0;j<n;j++) {
            arr[i][j] = s[j] - 'A';
        }
    }
    ll ans = 0;
    for (i=0;i<n-1;i++) {
        for (j=0;j<n;j++) {
            swap(arr[i][j], arr[i+1][j]);
            ans = max(ans, check(arr, j, 0));
            ans = max(ans, check(arr, i, 1));
            ans = max(ans, check(arr, i+1, 1));
            swap(arr[i][j], arr[i+1][j]);
        }
    }
    for (i=0;i<n-1;i++) {
        for (j=0;j<n;j++) {
            swap(arr[j][i], arr[j][i+1]);
            ans = max(ans, check(arr, j, 1));
            ans = max(ans, check(arr, i, 0));
            ans = max(ans, check(arr, i+1, 0));
            swap(arr[j][i], arr[j][i+1]);
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

