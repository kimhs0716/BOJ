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
constexpr ll MAX = 500'000;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

struct SEG {
    ll n;
    vl arr, seg, cnt;
    SEG(ll n) : n(n), arr(n), seg(n<<2), cnt(n<<2) {}
    void update(ll i, ll l, ll r, ll tar, ll diff) {
        if (l==r) {
            arr[tar] += diff;
            seg[i] = arr[tar] * (tar-MAX);
            cnt[i] += diff;
            return;
        }
        ll m = (l+r)>>1;
        if (tar<=m) update(i<<1, l, m, tar, diff);
        else update(i<<1|1, m+1, r, tar, diff);
        seg[i] = seg[i<<1] + seg[i<<1|1];
        cnt[i] = cnt[i<<1] + cnt[i<<1|1];
    }
    void update(ll tar, ll diff) {
        update(1, 0, n-1, tar, diff);
    }
    ll query(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return seg[i];
        ll m = (l+r)>>1;
        return query(i<<1, l, m, s, e) + query(i<<1|1, m+1, r, s, e);
    }
    ll query(ll s, ll e) {
        return query(1, 0, n-1, s, e);
    }
    ll count(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return cnt[i];
        ll m = (l+r)>>1;
        return count(i<<1, l, m, s, e) + count(i<<1|1, m+1, r, s, e);
    }
    ll count(ll s, ll e) {
        return count(1, 0, n-1, s, e);
    }
    ll kth(ll k) { // 1-based
        ll i=1, l=0, r=n-1;
        while (l<r) {
            ll m = (l+r)>>1;
            if (cnt[i<<1] >= k) {
                i = i<<1;
                r = m;
            }
            else {
                k -= cnt[i<<1];
                i = i<<1|1;
                l = m+1;
            }
        }
        return l;
    }
};

void solve(ll tc){
    ll i, j;
    ll n, m; cin>>n>>m;
    SEG seg(2*MAX+1);
    ll add = 0;
    ll cnt = n;
    ll total = 0;
    while (n--) {
        ll x; cin>>x;
        seg.update(x+MAX, 1);
        total += x;
    }
    while (m--) {
        ll a, x; cin>>a>>x;
        if (a==1) {
            seg.update(x-add+MAX, 1);
            cnt++;
            total += x;
        }
        else if (a==2) {
            add += x;
            total += x*cnt;
        }
        else if (a==3) {
            x = cnt-x;
            if (x==0) {
                cout<<total<<' ';
                continue;
            }
            ll k = seg.kth(x);
            ll ans = seg.query(0, k-1);
            ans += add*seg.count(0, k-1);
            ans += (x - seg.count(0, k-1)) * (k-MAX+add);
            cout<<total-ans<<' ';
        }
        else {
            ll k = seg.kth(x);
            ll ans = seg.query(0, k-1);
            ans += (x - seg.count(0, k-1)) * (k-MAX);
            cout<<ans + add*x<<' ';
        }
        // cout<<"add: "<<add<<endl;
        // for (i=1;i<=16;i++) cout<<i%10<<' ';
        // cout<<endl;
        // for (i=1;i<=16;i++) cout<<seg.count(i+MAX-add, i+MAX-add)<<' ';
        // cout<<endl;
    }
    cout<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
        // cout<<"=======\n";
    }
}
