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
constexpr ll INF = 1e15;

struct Node {
    ll data, lazy;
    Node *l, *r;
    Node() {
        data = lazy = 0;
        l = r = nullptr;
    }
    ~Node() {
        delete l;
        delete r;
    }
};

struct SEG {
    ll S, E;
    Node *root;
    SEG(ll s, ll e) : S(s), E(e) {
        root = new Node;
    }
    void relax(Node *cur, ll l, ll r) {
        if (cur && cur->lazy) {
            ll len = r-l+1;
            cur->data += len * cur->lazy;
            if (l!=r) {
                if (!cur->l) cur->l = new Node;
                cur->l->lazy += cur->lazy;
                if (!cur->r) cur->r = new Node;
                cur->r->lazy += cur->lazy;
            }
            cur->lazy = 0;
        }
    }
    void update(Node *cur, ll l, ll r, ll s, ll e, ll val) {
        relax(cur, l, r);
        if (r<s || e<l) return;
        if (s<=l && r<=e) {
            ll len = r-l+1;
            cur->data += len * val;
            if (l!=r) {
                if (!cur->l) cur->l = new Node;
                cur->l->lazy += val;
                if (!cur->r) cur->r = new Node;
                cur->r->lazy += val;
            }
            return;
        }
        ll m=l+r>>1;
        if (!cur->l) cur->l = new Node;
        update(cur->l, l, m, s, e, val);
        if (!cur->r) cur->r = new Node;
        update(cur->r, m+1, r, s, e, val);
        ll lv = cur->l->data;
        ll rv = cur->r->data;
        cur->data = lv + rv;
    }
    void update(ll s, ll e, ll val) {
        update(root, S, E, s, e, val);
    }
    ll query(Node *cur, ll l, ll r, ll s, ll e) {
        relax(cur, l, r);
        if (!cur) return 0;
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return cur->data;
        ll m=l+r>>1;
        return query(cur->l, l, m, s, e) + query(cur->r, m+1, r, s, e);
    }
    ll query(ll s, ll e) {
        return query(root, S, E, s, e);
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    ll q; cin>>q;
    vector<array<ll, 5>> queries(q);
    vl ans;
    for (i=0;i<q;i++) {
        auto &[a, b, c, d, e] = queries[i];
        cin>>a>>b>>c>>d;
        if (a==1) e = i-ans.size()+1;
        if (a==2) {
            e = ans.size();
            ans.push_back(-1);
        }
    }
    sort(queries.begin(), queries.end(), [](const auto &a, const auto &b) {
        ll aa = a[0]==1 ? a[4] : a[3];
        ll bb = b[0]==1 ? b[4] : b[3];
        if (aa==bb) {
            return a[0]<b[0];
        }
        return aa<bb;
    });
    SEG seg(1, 1e9);
    for (auto &[a, b, c, d, e] : queries) {
        // cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<endl;
        if (a==1) {
            seg.update(b, c, d);
        }
        else {
            ans[e] = seg.query(b, c);
            // cout<<ans[e]<<endl;
        }
        // for (i=1;i<=11;i++) cout<<seg.query(i, i)<<' '; cout<<endl;
    }
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

