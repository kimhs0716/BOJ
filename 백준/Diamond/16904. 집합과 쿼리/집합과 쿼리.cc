#include <bits/stdc++.h>

#include <utility>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = int;
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

// constexpr ll MOD = 1e9+7;
// // constexpr ll MOD = 998'244'353;
// constexpr ll INF = 1e18;
// constexpr ll MAX = 500'000;
// constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

struct GF2 {
    set<ll> basis;
    vl st;

    void add(ll x) {
        ll i;
        for (auto it=basis.rbegin(); it!=basis.rend(); it++) {
            ll b = *it;
            for (i=31;i>=0;i--)
                if ((b>>i)&1) break;
            if (((b>>i)&1) && ((x>>i)&1))
                x ^= b;
        }
        if (x) basis.insert(x);
        st.push_back(x);
    }

    void rollback() {
        ll b = st.back(); st.pop_back();
        if (b) basis.erase(b);
    }

    ll get() {
        ll x = 0;
        for (auto it=basis.rbegin(); it!=basis.rend(); it++) {
            ll b = *it;
            if ((x^b) > x)
                x ^= b;
        }
        return x;
    }
};

struct OFDC {
    ll q;
    vp query;
    unordered_map<ll, ll> in;
    vl ans;
    vvl seg;
    GF2 gf2;
    OFDC(vp &qq) : q(qq.size()), query(qq), seg((q+1)<<2) {
        for (ll i=0;i<q;i++) {
            auto [t, x] = query[i];
            // add
            if (t==1) in[x] = i;
            // remove
            else if (t==2) {
                ll s = in[x];
                ll e = i;
                update(1, 0, q, s, e, x);
                in.erase(x);
            }
        }
        for (auto [x, t] : in)
            update(1, 0, q, t, q, x);
        dfs(1, 0, q);
    }
    void update(ll i, ll l, ll r, ll s, ll e, ll x) {
        if (s<=l && r<=e) {
            seg[i].push_back(x);
            return;
        }
        ll m = (l+r)>>1;
        if (s<=m) update(i<<1, l, m, s, e, x);
        if (m+1<=e) update(i<<1|1, m+1, r, s, e, x);
    }
    void dfs(ll i, ll l, ll r) {
        for (auto x : seg[i])
            gf2.add(x);
        if (l==r) {
            if (l!=q) {
                auto [t, x] = query[l];
                if (t==3)
                    ans.push_back(gf2.get());
            }
        }
        else {
            ll m = (l+r)>>1;
            dfs(i<<1, l, m);
            dfs(i<<1|1, m+1, r);
        }
        for (auto x : seg[i])
            gf2.rollback();
    }
};

void solve(ll tc){
    ll i, j, k;
    ll n; cin>>n;
    vp query;
    while (n--) {
        ll x; cin>>x;
        query.push_back({1+(x<0), llabs(x)});
        query.push_back({3, -1});
    }
    OFDC ofdc(query);
    for (ll x : ofdc.ans) cout<<x<<' '; cout<<endl;
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
