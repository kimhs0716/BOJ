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

struct Node {
    ll val, idx;
    Node *l, *r;
    Node() {
        val = 0;
        idx = 0;
        l = r = nullptr;
    }
    ~Node() {
        if (l && l->idx == idx) delete l;
        if (r && r->idx == idx) delete r;
    }
};

struct PST {
    ll n;
    vector<Node*> roots;
    PST(ll n) : n(n) {
        roots.push_back(new Node());
        init(roots.back(), 0, n-1);
    }
    ~PST() {
        while (roots.size()) {
            delete roots.back();
            roots.pop_back();
        }
    }
    void init(Node *x, ll l, ll r) {
        if (l==r) return;
        ll m = (l+r)>>1;
        x->l = new Node();
        init(x->l, l, m);
        x->r = new Node();
        init(x->r, m+1, r);
    }
    void update(Node *x, ll tar, ll diff) {
        ll idx = roots.size();
        Node *y = new Node();
        y->idx = idx;
        roots.push_back(y);
        ll l=0, r=n-1;
        vector<Node*> st;
        while (l<r) {
            st.push_back(y);
            ll m = (l+r)>>1;
            if (tar<=m) {
                y->l = new Node();
                y->l->idx = idx;
                y->r = x->r;
                y = y->l;
                x = x->l;
                r = m;
            }
            else {
                y->r = new Node();
                y->r->idx = idx;
                y->l = x->l;
                y = y->r;
                x = x->r;
                l = m+1;
            }
        }
        y->val = x->val + diff;
        while (st.size()) {
            y = st.back(); st.pop_back();
            y->val = y->l->val + y->r->val;
        }
    }
    void update(ll pr, ll tar, ll diff) {
        update(roots[pr], tar, diff);
    }
    ll query(Node *x, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return x->val;
        ll m = (l+r)>>1;
        return query(x->l, l, m, s, e) + query(x->r, m+1, r, s, e);
    }
    ll query(ll i, ll s, ll e) {
        return query(roots[i], 0, n-1, s, e);
    }
    ll kth(Node *u, Node *v, Node *lca, Node *lcap, ll k) {
        ll l=0, r=n-1;
        while (l<r) {
            ll m = (l+r)>>1;
            ll diff = u->l->val + v->l->val - lca->l->val - lcap->l->val;
            if (diff>=k) {
                u = u->l;
                v = v->l;
                lca = lca->l;
                lcap = lcap->l;
                r = m;
            }
            else {
                u = u->r;
                v = v->r;
                lca = lca->r;
                lcap = lcap->r;
                l = m+1;
                k -= diff;
            }
        }
        return l;
    }
    ll kth(ll u, ll v, ll lca, ll lcap, ll k) {
        return kth(roots[u], roots[v], roots[lca], roots[lcap], k);
    }
};

void solve(ll tc){
    ll i, j;
    ll n, m; cin>>n>>m;
    vl arr(n+1);
    for (i=1;i<=n;i++) cin>>arr[i];
    vl comp(arr.begin()+1, arr.end());
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (auto &x : arr)
        x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    // cout<<arr<<endl;
    vvl adj(n+1);
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    PST pst(comp.size());
    vl id(n+1), depth(n+1);
    ll time = 1;
    vvl anc(17, vl(n+1));
    function<void(ll, ll)> dfs = [&pst, &arr, &adj, &id, &depth, &anc, &time, &dfs](ll cur, ll par) {
        id[cur] = time++;
        anc[0][id[cur]] = id[par];
        pst.update(id[par], arr[cur], 1);
        depth[id[cur]] = depth[id[par]]+1;
        for (ll nxt : adj[cur]) {
            if (nxt == par) continue;
            dfs(nxt, cur);
        }
    };
    dfs(1, 0);
    for (i=1;i<17;i++) {
        for (j=0;j<=n;j++) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
        }
    }
    // cout<<id<<endl;
    // cout<<anc[0]<<endl;
    // cout<<anc[1]<<endl;
    function<ll(ll, ll)> lca = [&anc, &depth](ll u, ll v) {
        if (depth[u] > depth[v]) swap(u, v);
        ll diff = depth[v] - depth[u];
        for (ll i=0;i<17;i++) {
            if (diff&1) v = anc[i][v];
            diff >>= 1;
        }
        if (u==v) return u;
        for (ll i=16;i>=0;i--) {
            ll pu = anc[i][u];
            ll pv = anc[i][v];
            if (pu != pv) {
                u = pu;
                v = pv;
            }
        }
        return anc[0][u];
    };
    while (m--) {
        ll u, v, k; cin>>u>>v>>k;
        u = id[u];
        v = id[v];
        ll l = lca(u, v);
        ll lp = anc[0][l];
        // cout<<u<<' ';
        // cout<<v<<' ';
        // cout<<l<<' ';
        // cout<<lp<<' ';
        cout<<comp[pst.kth(u, v, l, lp, k)]<<endl;
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
