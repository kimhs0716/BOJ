#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

void setup() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

// usage: iterSEG(n, arr); update(tar, val); ll sum = query(qs, qe);
// memo : 0-indexed
struct iterSEG {
    ll n;
    vl seg;

    iterSEG(ll size,vl& arr){
        n=1; while (n<size) n<<=1;
        seg.assign(2*n,0);
        for (ll i=0;i<size;++i) seg[i+n]=arr[i];
        for (ll i=n-1;i>0;--i) seg[i]=seg[i<<1]+seg[i<<1|1];
    }

    void update(ll tar, ll val) {
        ll p=tar+n;
        seg[p]=val;
        for (p>>=1;p;p>>=1) seg[p]=seg[p<<1]+seg[p<<1|1];
    }

    ll query(ll l,ll r) {
        ll res=0;
        for (l+=n,r+=n;l<=r;l>>=1,r>>=1) {
            if (l&1) res+=seg[l++];
            if (!(r&1)) res+=seg[r--];
        }
        return res;
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll tc) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n);
    ll prev;
    cin >> prev;
    arr[0] = prev;
    for (i=1;i<n;++i) {
        ll x; cin>>x;
        arr[i]=x-prev;
        prev=x;
    }
    iterSEG seg(n, arr);
    ll q; cin>>q;
    while (q--) {
        ll type; cin>>type;
        if (type==1) {
            cin>>i>>j>>k;
            arr[i-1]+=k;
            seg.update(i-1, arr[i-1]);
            if (j<n) {
                arr[j]-=k;
                seg.update(j, arr[j]);
            }
        }
        else {
            cin>>i;
            cout<<seg.query(0, i-1)<<endl;
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