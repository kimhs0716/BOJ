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
    SEG(vl &arr) : n(arr.size()), arr(arr), seg(n<<2) {
        init(1, 0, n-1);
    }
    void init(ll i, ll l, ll r) {
        if (l==r) {
            seg[i] = l;
            return;
        }
        ll m=l+r>>1;
        init(i<<1, l, m);
        init(i<<1|1, m+1, r);
        ll left = seg[i<<1], right = seg[i<<1|1];
        if (left==-1) seg[i] = right;
        else if (right==-1) seg[i] = left;
        else if (arr[left]==arr[right]) seg[i] = min(left, right);
        else seg[i] = arr[left]<arr[right] ? left : right;
    }
    void update(ll i, ll l, ll r, ll tar, ll val) {
        if (l==r) {
            arr[tar] = val;
            return;
        }
        ll m=l+r>>1;
        if (tar<=m) update(i<<1, l, m, tar, val);
        else update(i<<1|1, m+1, r, tar, val);
        ll left = seg[i<<1], right = seg[i<<1|1];
        if (left==-1) seg[i] = right;
        else if (right==-1) seg[i] = left;
        else if (arr[left]==arr[right]) seg[i] = min(left, right);
        else seg[i] = arr[left]<arr[right] ? left : right;
    }
    void update(ll tar, ll val) {
        update(1, 0, n-1, tar, val);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        if (s<=l && r<=e) return seg[i];
        if (r<s || e<l) return -1;
        ll m=l+r>>1;
        ll left = query(i<<1, l, m, s, e);
        ll right = query(i<<1|1, m+1, r, s, e);
        if (left==-1) return right;
        else if (right==-1) return left;
        else if (arr[left]==arr[right]) return min(left, right);
        else return arr[left]<arr[right] ? left : right;
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    SEG seg(arr);
    ll q; cin>>q;
    while (q--) {
        ll a, b, c; cin>>a>>b>>c;
        if (a==1) {
            seg.update(b-1, c);
        }
        else {
            cout<<seg.query(b-1, c-1)+1<<endl;
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

