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
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
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
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    sort(arr.begin(), arr.end());
    // cout<<arr<<endl;
    ll ans=0;
    for (i=0;i<n-2;i++) {
        ll T = -arr[i];
        ll l=i+1, r=n-1;
        while (l<r) {
            ll S=arr[l]+arr[r];
            if (S<T) l++;
            else if (S>T) r--;
            else {
                // cout<<i<<": "<<arr[i]<<endl;
                // cout<<l<<": "<<arr[l]<<endl;
                // cout<<r<<": "<<arr[r]<<endl;
                if (arr[l]==arr[r]) {
                    ans += (r-l+1)*(r-l)/2;
                    // cout<<ans<<endl<<endl;
                    break;
                }
                ll cntL=0, cntR=0;
                while (arr[l]==arr[l+(++cntL)]);
                while (arr[r]==arr[r-(++cntR)]);
                ans += cntL * cntR;
                l += cntL;
                r -= cntR;
                // cout<<ans<<endl<<endl;
            }
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