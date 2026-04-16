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

vl bm = {
    0b111101101101111,
    0b001001001001001,
    0b111001111100111,
    0b111001111001111,
    0b101101111001001,
    0b111100111001111,
    0b111100111101111,
    0b111001001001001,
    0b111101111101111,
    0b111101111001111
};

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vector<string> arr(5); cin>>arr;
    ld ans=0;
    for (i=0;i<4*n;i+=4) {
        ll cur = 0;
        for (j=0;j<5;j++) {
            for (k=0;k<3;k++) {
                cur <<= 1;
                cur |= arr[j][i+k]=='#';
            }
        }
        ll sum=0, cnt=0;
        for (j=0;j<10;j++) {
            if ((bm[j]&cur)==cur) {
                sum += j;
                cnt++;
            }
        }
        if (!cnt) {
            cout<<"-1\n";
            return;
        }
        ans *= 10;
        ans += (ld)sum/cnt;
    }
    cout<<fixed<<setprecision(15);
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

