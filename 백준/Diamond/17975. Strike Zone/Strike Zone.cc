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

struct node {
    ll l, r, sum, best;
};

node merge(node l, node r) {
    node ret;
    ret.l = max(l.l, l.sum + r.l);
    ret.r = max(r.r, r.sum + l.r);
    ret.sum = l.sum + r.sum;
    ret.best = max({l.best, r.best, l.r + r.l});
    return ret;
}

struct SEG {
    ll n;
    vl arr;
    vector<node> seg;
    SEG(vl &a) : n(a.size()), arr(a), seg(n<<2) {
        init(1, 0, n-1);
    }
    void init(ll i, ll l, ll r) {
        if (l==r) {
            ll x = arr[l];
            seg[i] = {x, x, x, x};
            return;
        }
        ll m = (l+r)>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        seg[i] = merge(seg[i<<1], seg[i<<1|1]);
    }
    node query(ll i, ll l, ll r, ll s, ll e) {
        if (s<=l && r<=e) return seg[i];
        if (r<s || e<l) return {-INF, -INF, 0, -INF};
        ll m = (l+r)>>1;
        return merge(query(i<<1, l, m, s, e), query(i<<1|1, m+1, r, s, e));
    }
    node query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            arr[tar] = val;
            seg[i] = {val, val, val, val};
            return;
        }
        ll m = (l+r)>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        seg[i] = merge(seg[i<<1], seg[i<<1|1]);
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
    }
};

map<ll, ll> compress(vl arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    map<ll, ll> ret;
    for (ll i=0; i<arr.size(); i++)
        ret[arr[i]] = i;
    return ret;
}

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    vl x_pos;
    ll n;
    cin>>n;
    vector<array<ll, 3>> strikes(n);
    for (auto &[x, y, c] : strikes) {
        cin>>x>>y;
        x_pos.push_back(x);
    }
    cin>>n;
    vector<array<ll, 3>> balls(n);
    for (auto &[x, y, c] : balls) {
        cin>>x>>y;
        x_pos.push_back(x);
    }
    ll c1, c2; cin>>c1>>c2;
    for (auto &[x, y, c] : strikes) c = c1;
    for (auto &[x, y, c] : balls) c = -c2;
    map<ll, ll> x_comp = compress(x_pos);
    map<ll, vp> pts;
    for (auto &[x, y, c] : strikes) pts[y].push_back({x_comp[x], c});
    for (auto &[x, y, c] : balls) pts[y].push_back({x_comp[x], c});
    ll ans = 0;
    for (auto it = pts.begin(); it != pts.end(); it++) {
        vl arr(x_comp.size());
        SEG seg(arr);
        for (auto it2 = it; it2 != pts.end(); it2++) {
            for (auto &[x, c] : it2->second) {
                arr[x] += c;
                seg.update(x, arr[x]);
            }
            // cout<<arr<<endl;
            // node t = seg.query(0, arr.size()-1);
            // cout<<"l: "<<t.l<<", "<<"r: "<<t.r<<", "<<"sum: "<<t.sum<<", "<<"best: "<<t.best<<endl<<endl;
            ans = max(ans, seg.query(0, arr.size()-1).best);
        }
    }
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

