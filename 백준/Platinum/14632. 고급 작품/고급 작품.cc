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
    ll r, c; cin>>r>>c;
    ll n; cin>>n;
    vector<vector<string>> stamps;
    while (n--) {
        ll x, y; cin>>x>>y;
        vector<string> s(x);
        cin>>s;
        stamps.push_back(s);
    }
    vector<string> arr(r, string(c, '.'));
    vvl nxt(r, vl(c+1));
    for (i=0;i<r;i++) {
        for (j=0;j<=c;j++) {
            nxt[i][j] = j;
        }
    }

    ll m; cin>>m;
    vector<tlll> query(m);
    for (auto &[t, x, y] : query) {
        cin>>t>>x>>y;
        --t;
    }
    reverse(query.begin(), query.end());

    vl st;
    for (auto [t, x, y] : query) {
        ll h = stamps[t].size();
        ll w = stamps[t][0].size();
        for (i=x;i<x+h;i++) {
            st.clear();
            j = y;
            while (1) {
                while (nxt[i][j] != j) j = nxt[i][j];
                if (j >= y+w) break;
                st.push_back(j);
                arr[i][j] = stamps[t][i - x][j - y];
                ++j;
            }
            while (nxt[i][j] != j) j = nxt[i][j];
            while (st.size()) {
                ll k = st.back(); st.pop_back();
                nxt[i][k] = j;
            }
        }
    }
    for (auto &s : arr)
        cout<<s<<endl;
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
