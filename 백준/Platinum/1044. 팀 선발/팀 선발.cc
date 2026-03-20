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
constexpr ll INF = 1e18;
constexpr ll MAX = 500'000;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    ll l=n/2, r=n-l;
    vp left(l), right(r);
    for (i=0;i<l;i++) cin>>left[i].first;
    for (i=0;i<r;i++) cin>>right[i].first;
    for (i=0;i<l;i++) cin>>left[i].second;
    for (i=0;i<r;i++) cin>>right[i].second;
    map<ll, map<ll, ll>> ld, rd;
    for (i=0;i<(1LL<<l);i++) {
        ll p = __builtin_popcountll(i);
        ll s = 0;
        for (j=0;j<l;j++) {
            if ((i>>j)&1) s -= left[l-j-1].second;
            else s += left[l-j-1].first;
        }
        if (ld[p].count(s)==0) ld[p][s] = i;
        else ld[p][s] = min(ld[p][s], i);
    }
    for (i=0;i<(1LL<<r);i++) {
        ll p = __builtin_popcountll(i);
        ll s = 0;
        for (j=0;j<r;j++) {
            if ((i>>j)&1) s -= right[r-j-1].second;
            else s += right[r-j-1].first;
        }
        if (rd[p].count(s)==0) rd[p][s] = i;
        else rd[p][s] = min(rd[p][s], i);
    }
    // for (auto &[p, m] : ld) {
    //     cout<<"=== "<<p<<" ===\n";
    //     for (auto &[s, mask] : m) {
    //         cout<<s<<": "<<mask<<endl;
    //     }
    // }
    // for (auto &[p, m] : rd) {
    //     cout<<"=== "<<p<<" ===\n";
    //     for (auto &[s, mask] : m) {
    //         cout<<s<<": "<<mask<<endl;
    //     }
    // }
    ll ans = INF, am = -1;
    for (auto &[p, m] : ld) {
        for (auto &[s, mask] : m) {
            auto it = rd[l-p].lower_bound(-s);
            if (it != rd[l-p].end()) {
                ll cur = llabs(s + it->first);
                if (cur<ans) {
                    ans = cur;
                    am = (mask<<r) | it->second;
                }
                if (cur==ans) {
                    am = min(am, (mask<<r) | it->second);
                }
            }
            if (it != rd[l-p].begin()) {
                ll cur = llabs(s + prev(it)->first);
                if (cur<ans) {
                    ans = cur;
                    am = (mask<<r) | prev(it)->second;
                }
                if (cur==ans) {
                    am = min(am, (mask<<r) | prev(it)->second);
                }
            }
        }
    }
    // cout<<ans<<endl;
    for (i=n-1;i>=0;i--) cout<<((am>>i)&1)+1<<' ';
    cout<<endl;
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
