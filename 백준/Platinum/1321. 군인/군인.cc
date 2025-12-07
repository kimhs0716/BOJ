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
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            arr[tar] += val;
            seg[i] = arr[tar];
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
    }
    ll kth(ll k) {
        ll i=1, l=0, r=n-1;
        while (l!=r) {
            ll m=l+r>>1;
            if (seg[i<<1] < k) {
                k -= seg[i<<1];
                i = i<<1|1;
                l = m+1;
            }
            else {
                i = i<<1;
                r = m;
            }
        }
        return l;
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    SEG seg(arr);
    ll q; cin>>q;
    while (q--) {
        ll a, b, c; cin>>a>>b;
        if (a==1) {
            cin>>c;
            seg.update(b-1, c);
        }
        else {
            cout<<seg.kth(b)+1<<endl;
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

