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

struct SEG {
    ll n;
    vl arr;
    vector<node> seg;
    SEG(vl &arr) : n(arr.size()), arr(arr), seg(n<<2) {
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
        node left = seg[i<<1];
        node right = seg[i<<1|1];
        seg[i].l = max(left.l, left.sum + right.l);
        seg[i].r = max(right.r, right.sum + left.r);
        seg[i].sum = left.sum + right.sum;
        seg[i].best = max({left.best, right.best, left.r+right.l});
    }
    node query(ll i, ll l, ll r, ll s, ll e) {
        if (s<=l && r<=e) return seg[i];
        if (e<l || r<s) return {-INF, -INF, 0, -INF};
        ll m = (l+r)>>1;
        node left = query(i<<1, l, m, s, e);
        node right = query(i<<1|1, m+1, r, s, e);
        node ret{};
        ret.l = max(left.l, left.sum + right.l);
        ret.r = max(right.r, right.sum + left.r);
        ret.sum = left.sum + right.sum;
        ret.best = max({left.best, right.best, left.r+right.l});
        return ret;
    }
    node query(ll s, ll e) {
        if (s>e) return {-INF, -INF, 0, -INF};
        if (s==e) return {arr[s], arr[s], arr[s], arr[s]};
        return query(1, 0, n-1, s, e);
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            seg[i] = {val, val, val, val};
            return;
        }
        ll m = (l+r)>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        node left = seg[i<<1];
        node right = seg[i<<1|1];
        seg[i].l = max(left.l, left.sum + right.l);
        seg[i].r = max(right.r, right.sum + left.r);
        seg[i].sum = left.sum + right.sum;
        seg[i].best = max({left.best, right.best, left.r+right.l});
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
        arr[tar] = val;
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    SEG seg(arr);
    ll q; cin>>q;
    while (q--) {
        ll a, b, c, d; cin>>a>>b>>c>>d;
        --a; --b; --c; --d;
        if (c<=b) {
            if (b==d) {
                if (c==a) {
                    cout<<seg.query(a, b).best<<endl;
                }
                else if (b==c) {
                    cout<<seg.query(a, b).r<<endl;
                }
                else {
                    ll ans = seg.query(c, b).best;
                    ans = max(ans, seg.query(c, b).l + seg.query(a, c).r - arr[c]);
                    cout<<ans<<endl;
                }
            }
            else {
                if (a==c) {
                    if (b==c) {
                        cout<<seg.query(c, d).l<<endl;
                    }
                    else {
                        ll ans = seg.query(a, b).best;
                        ans = max(ans, seg.query(a, b).r + seg.query(b, d).l - arr[b]);
                        cout<<ans<<endl;
                    }
                }
                else {
                    if (c==b) {
                        cout<<seg.query(a, b).r + seg.query(c, d).l - arr[b]<<endl;
                    }
                    else {
                        // cout<<"1: "<<seg.query(a, c).r<<' '<<seg.query(c, d).l<<' '<<arr[c]<<endl;
                        // cout<<"2: "<<seg.query(a, b).r<<' '<<seg.query(b, d).l<<' '<<arr[b]<<endl;
                        // cout<<"3: "<<seg.query(a, c).r<<' '<<seg.query(c, b).sum<<' '<<seg.query(b, d).l<<' '<<arr[c]<<' '<<arr[b]<<endl;
                        // cout<<"4: "<<seg.query(c, b).best<<endl;
                        ll ans = -INF;
                        ans = max(ans, seg.query(a, c).r + seg.query(c, d).l - arr[c]);
                        ans = max(ans, seg.query(a, b).r + seg.query(b, d).l - arr[b]);
                        ans = max(ans, seg.query(a, c).r + seg.query(c, b).sum + seg.query(b, d).l - arr[c] - arr[b]);
                        ans = max(ans, seg.query(c, b).best);
                        cout<<ans<<endl;
                    }
                }
            }
        }
        else {
            node left = seg.query(a, b);
            node mid = seg.query(b, c);
            node right = seg.query(c, d);
            // cout<<"left: {"<<left.l<<", "<<left.r<<", "<<left.sum<<", "<<left.best<<"}"<<endl;
            // cout<<"mid: {"<<mid.l<<", "<<mid.r<<", "<<mid.sum<<", "<<mid.best<<"}"<<endl;
            // cout<<"right: {"<<right.l<<", "<<right.r<<", "<<right.sum<<", "<<right.best<<"}"<<endl;
            cout<<left.r + mid.sum + right.l - arr[b] - arr[c]<<endl;
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

