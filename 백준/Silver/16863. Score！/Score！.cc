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
using ull = unsigned long long;

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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

struct SegTree {
    ll n;
    vl &arr, tree;
    SegTree(vl &d) : n(d.size()), arr(d), tree(n<<2) {
        segInit(1, 0, n-1);
    }
    void segInit(ll i, ll s, ll e) {
        if (s==e) {
            tree[i]=arr[s];
            return;
        }
        ll mid=s+e>>1;
        segInit(i<<1, s, mid);
        segInit(i<<1|1, mid+1, e);
        tree[i]=tree[i<<1]+tree[i<<1|1];
    }
    ll segQeury(ll i, ll l, ll r, ll s, ll e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return tree[i];
        ll mid=l+r>>1;
        return segQeury(i<<1, l, mid, s, e) + segQeury(i<<1|1, mid+1, r, s, e);
    }
    ll query(ll s, ll e) { return segQeury(1, 0, n-1, s, e); }
    void segUpdate(ll i, ll l, ll r, ll pos, ll val) {
        if (r<pos || pos<l) return;
        if (l==r) {
            tree[i]=val;
            return;
        }
        ll mid=l+r>>1;
        segUpdate(i<<1, l, mid, pos, val);
        segUpdate(i<<1|1, mid+1, r, pos, val);
        tree[i]=tree[i<<1]+tree[i<<1|1];
    }
    void update(ll pos, ll val) { segUpdate(1, 0, n-1, pos, val); }
    ll find(ll t) {
        ll lo=0, hi=n-1;
        while (lo<hi) {
            ll mid=lo+hi>>1;
            ll cur=query(0, mid);
            if (cur<t) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll testcase){
    ll i, j;
    ll n; cin>>n;
    ll hs = 0, as = 0;
    ll ht = 0, at = 0;
    ll time = 0;
    while (n--) {
        char team, dummy;
        ll score, m, s;
        cin>>team>>score>>m>>dummy>>s;
        ll t = m * 60 + s - time;
        if (hs > as) ht += t;
        else if (hs < as) at += t;
        time += t;
        if (team == 'H') hs += score;
        else as += score;
    }
    if (hs > as) {
        ht += 1920 - time;
        cout<<"H ";
    }
    else {
        at += 1920 - time;
        cout<<"A ";
    }
    cout<<ht/60<<':'<<setfill('0')<<setw(2)<<ht%60<<' ';
    cout<<at/60<<':'<<setfill('0')<<setw(2)<<at%60<<' ';
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