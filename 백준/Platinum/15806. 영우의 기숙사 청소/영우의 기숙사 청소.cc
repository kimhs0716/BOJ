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

vp moves = {
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
};
void solve(ll tc){
    ll i, j;
    ll n, m, k, t; cin>>n>>m>>k>>t;
    unordered_set<bitset<90000>> s;
    vvl arr(n, vl(n));
    while (m--) {
        ll x, y; cin>>x>>y;
        arr[x-1][y-1] = 1;
    }
    function to_bitset = [n](vvl &a) {
        bitset<90000> ret;
        for (ll i=0;i<n;i++) {
            for (ll j=0;j<n;j++) {
                ret[i*n+j] = a[i][j];
            }
        }
        return ret;
    };
    for (ll time=0; time<t; time++) {
        // cout<<"===== "<<time<<" =====\n";
        // for (i=0;i<n;i++) {
        //     for (j=0;j<n;j++) {
        //         cout<<arr[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        auto bs = to_bitset(arr);
        if (s.contains(bs) && (time%2==t%2)) {
            break;
        }
        s.insert(bs);
        vvl temp(n, vl(n));
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                if (arr[i][j]) {
                    for (auto [dr, dc] : moves) {
                        ll nr = i+dr;
                        ll nc = j+dc;
                        if (nr<0 || nr>=n) continue;
                        if (nc<0 || nc>=n) continue;
                        temp[nr][nc] = 1;
                    }
                }
            }
        }
        swap(arr, temp);
    }
    // cout<<"=============\n";
    // for (i=0;i<n;i++) {
    //     for (j=0;j<n;j++) {
    //         cout<<arr[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    bool ans = 0;
    while (k--) {
        ll x, y; cin>>x>>y;
        ans |= arr[x-1][y-1];
    }
    if (!ans) cout<<"NO\n";
    else cout<<"YES\n";
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
