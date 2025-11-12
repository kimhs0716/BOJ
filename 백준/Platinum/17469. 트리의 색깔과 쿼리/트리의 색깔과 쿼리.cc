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

struct UF {
    ll n;
    vl par, sz;
    vector<set<ll>> s;
    UF(ll n, vl &arr) : n(n), par(n), sz(n, 1), s(n) {
        iota(par.begin(), par.end(), 0);
        for (ll i=0; i<n; i++)
            s[i].insert(arr[i]);
    }
    ll find(ll x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        if (s[x].size() < s[y].size()) swap(s[x], s[y]);
        for (auto i: s[y]) s[x].insert(i);
    }
    ll query(ll x) {
        return s[find(x)].size();
    }
    void debug() {
        cout<<"par: "<<par<<endl;
        cout<<"sz : "<<sz<<endl;
        cout<<"=== set ===\n";
        for (ll i=0; i<n; i++) {
            cout<<i<<": ";
            for (auto x: s[i]) cout<<x<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, q; cin>>n>>q;
    vl par(n), color(n);
    for (i=1;i<n;i++) {
        cin>>par[i];
        par[i]--;
    }
    cin>>color;
    UF uf(n, color);
    vector<array<ll, 2>> query(n+q-1);
    for (auto &[t, c] : query) {
        cin>>t>>c;
        --c;
    }
    reverse(query.begin(), query.end());
    vl ans;
    for (auto [t, c] : query) {
        if (t==1) {
            uf.join(c, par[c]);
        }
        else {
            ans.push_back(uf.query(c));
        }
        // uf.debug();
    }
    reverse(ans.begin(), ans.end());
    for (auto x: ans) cout<<x<<endl;
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

