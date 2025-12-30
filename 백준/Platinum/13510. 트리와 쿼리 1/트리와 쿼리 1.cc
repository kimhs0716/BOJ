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
constexpr ll INF = 1e15;

struct SEG {
    ll n;
    vl arr, seg;
    SEG(vl &a) : n(a.size()), arr(a), seg(n<<2) {
        init(1, 0, n-1);
    }
    void init(ll i, ll l, ll r) {
        if (l==r) {
            seg[i] = arr[l];
            return;
        }
        ll m=l+r>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            arr[tar] = val;
            seg[i] = val;
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return seg[i];
        ll m=l+r>>1;
        return max(query(i<<1, l, m, s, e), query(i<<1|1, m+1, r, s, e));
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vvp adj(n);
    adj[0].push_back({-1, -1});
    vp edges(n-1);
    for (i=0;i<n-1;i++) {
        ll u, v, w; cin>>u>>v>>w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges[i] = {u, v};
    }
    function<ll(ll, ll)> dfs1 = [&adj, &dfs1](ll cur, ll par) -> ll {
        ll mx = -1, ret = 1;
        for (ll i=1;i<adj[cur].size();i++) {
            auto [nxt, w] = adj[cur][i];
            if (nxt==par) {
                swap(adj[cur][0], adj[cur][i]);
                i--;
                continue;
            }
            ll t = dfs1(nxt, cur);
            if (t > mx) {
                swap(adj[cur][i], adj[cur][1]);
                mx = t;
            }
            ret += t;
        }
        return ret;
    };
    dfs1(0, -1);
    vl in(n), out(n), top(n), arr(n), dep(n);
    function<ll(ll, ll, ll, ll)> dfs2 = [&adj, &in, &out, &top, &arr, &dep, &dfs2](ll cur, ll par, ll cost, ll time) -> ll {
        in[cur] = time;
        arr[in[cur]] = cost;
        for (auto [nxt, w] : adj[cur]) {
            if (nxt==par) continue;
            if (adj[cur][1].first == nxt) top[nxt] = top[cur];
            else top[nxt] = nxt;
            dep[nxt] = dep[cur] + 1;
            time = dfs2(nxt, cur, w, time+1);
        }
        return out[cur] = time;
    };
    dfs2(0, -1, 0, 0);
    // cout<<in<<endl;
    // cout<<out<<endl;
    // cout<<top<<endl;
    // cout<<arr<<endl;
    // cout<<dep<<endl;
    SEG seg(arr);
    ll q; cin>>q;
    while (q--) {
        ll a, b, c; cin>>a>>b>>c;
        if (a==1) {
            auto [u, v] = edges[b-1];
            if (dep[u]>dep[v]) swap(u, v);
            seg.update(in[v], c);
        }
        else {
            ll res = 0;
            --b; --c;
            while (top[b] != top[c]) {
                if (dep[top[b]]>dep[top[c]]) swap(b, c);
                res = max(res, seg.query(in[top[c]], in[c]));
                c = adj[top[c]][0].first;
            }
            if (in[b]>in[c]) swap(b, c);
            res = max(res, seg.query(in[b]+1, in[c]));
            cout<<res<<endl;
        }
    }
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
