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
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vector<string> arr(n); cin>>arr;
    vl cur(n);
    ll q; cin>>q;
    while (q--) {
        ll a, b; cin>>a>>b;
        --a;
        ll left = a;
        while (left>0 && arr[left-1][(cur[left-1]+2)%8]!=arr[left][(cur[left]+6)%8])
            left--;
        // cout<<left<<endl;
        ll right = a;
        while (right<n-1 && arr[right+1][(cur[right+1]+6)%8]!=arr[right][(cur[right]+2)%8])
            right++;
        // cout<<right<<endl;
        b = -b;
        ll tb = -b;
        cur[a] = (cur[a]+b+8)%8;
        for (i=a-1;i>=left;i--) {
            cur[i] = (cur[i]+tb+8)%8;
            tb = -tb;
        }
        tb = -b;
        for (i=a+1;i<=right;i++) {
            cur[i] = (cur[i]+tb+8)%8;
            tb = -tb;
        }
        // for (i=0;i<n;i++) {
        //     for (j=0;j<8;j++)
        //         cout<<arr[i][(cur[i]+j)%8]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    ll ans = 0;
    for (i=0;i<n;i++) {
        if (arr[i][cur[i]]=='1') ans++;
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

