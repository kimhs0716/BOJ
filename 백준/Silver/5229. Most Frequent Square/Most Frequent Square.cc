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
    ll n; cin>>n;
    vl x(n), y(n);
    for (i=0;i<n;i++) cin>>x[i]>>y[i];
    map<ll, ll> cnt;
    for (ll a=0;a<n;a++) {
        for (ll b=0;b<n;b++) {
            for (ll c=0;c<n;c++) {
                for (ll d=0;d<n;d++) {
                    if (a==b || b==c || c==d || d==a || a==c || b==d) continue;
                    if (x[a]!=x[b]) continue;
                    if (x[c]!=x[d]) continue;
                    if (y[a]!=y[d]) continue;
                    if (y[b]!=y[c]) continue;
                    if (x[a]-x[c]!=y[a]-y[c]) continue;
                    cnt[llabs(y[a]-y[b])]++;
                }
            }
        }
    }
    ll ans=0, max_cnt=0;
    for (auto [l, c] : cnt) {
        // cout<<l<<' '<<c<<endl;
        if (c>=max_cnt) ans=l, max_cnt=c;
    }
    if (max_cnt) cout<<"LENGTH = "<<ans<<", COUNT = "<<max_cnt/2<<endl;
    else cout<<"No squares among the points.\n";
}


int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}