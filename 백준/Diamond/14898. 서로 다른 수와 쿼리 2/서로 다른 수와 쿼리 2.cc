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

int make_node() {
    static int top = 0;
    return top++;
}
int seg[132000005]; // { val, l, r }
struct PST {
    int n;
    vector<int> roots, st;
    PST(int n) : n(n) {
        int id = make_node();
        roots.push_back(id);
        init(id, 0, n-1);
    }
    void init(int i, int l, int r) {
        if (l==r) return;
        int m = (l+r)>>1;
        int left = make_node(), right = make_node();
        seg[3*i+1] = left;
        seg[3*i+2] = right;
        init(left, l, m);
        init(right, m+1, r);
    }
    void update(int tar, int diff, bool overwrite = false) {
        int x = roots.back();
        int y = make_node();
        if (overwrite) roots.pop_back();
        roots.push_back(y);
        int l = 0, r = n-1;
        while (l<r) {
            st.push_back(y);
            int m = (l+r)>>1;
            if (tar <= m) {
                seg[3*y+2] = seg[3*x+2];
                seg[3*y+1] = make_node();
                r = m;
                x = seg[3*x+1];
                y = seg[3*y+1];
            }
            else {
                seg[3*y+1] = seg[3*x+1];
                seg[3*y+2] = make_node();
                l = m+1;
                x = seg[3*x+2];
                y = seg[3*y+2];
            }
        }
        seg[3*y] = seg[3*x] + diff;
        while (st.size()) {
            y = st.back(); st.pop_back();
            int left = seg[3*y+1];
            int right = seg[3*y+2];
            seg[3*y] = seg[3*left] + seg[3*right];
        }
    }
    int query(int i, int l, int r, int s, int e) {
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return seg[3*i];
        int m = (l+r)>>1;
        return query(seg[3*i+1], l, m, s, e) + query(seg[3*i+2], m+1, r, s, e);
    }
    int query(int i, int s, int e) {
        return query(roots[i], 0, n-1, s, e);
    }
};

void solve(ll tc){
    int i, j;
    int n; cin>>n;
    vector<int> arr(n); cin>>arr;
    vector<int> comp = arr;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (auto &x : arr)
        x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    // cout<<arr<<endl;
    vector<int> prev(comp.size(), -1);
    PST pst(n);
    for (i=0;i<n;i++) {
        int x = arr[i];
        pst.update(i, 1);
        if (prev[x] != -1) pst.update(prev[x], -1, true);
        prev[x] = i;
        // for (j=0;j<n;j++) cout<<pst.query(i+1, j, j)<<' '; cout<<endl;
    }
    int q; cin>>q;
    int qi = 0;
    while (q--) {
        int x, r; cin>>x>>r;
        qi = pst.query(r, qi+x-1, r-1);
        cout<<qi<<endl;
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
