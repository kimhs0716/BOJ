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
    ll data, dp, idx;
    Node *l, *r;
    Node(ll x, ll idx) : data(x), dp(0), idx(idx), l(nullptr), r(nullptr) {}
    ~Node() {
        delete l;
        delete r;
    }
    ll dfs1() {
        if (l) dp = max(dp, l->dfs1());
        if (r) dp = max(dp, r->dfs1());
        return dp += 1;
    }
    tlll dfs2() {
        ll ret=-1, ans=-1, i=-1;
        ll lh = 0, rh = 0;
        if (l) {
            lh = l->dp;
            auto [a, b, c] = l->dfs2();
            if (ret<a || (ret==a && c<i)) {
                ret = a;
                ans = b;
                i = c;
            }
        }
        if (r) {
            rh = r->dp;
            auto [a, b, c] = r->dfs2();
            if (ret<a || (ret==a && c<i)) {
                ret = a;
                ans = b;
                i = c;
            }
        }
        ll a=llabs(rh-lh), b=data, c=idx;
        if (ret<a || (ret==a && c<i)) {
            ret = a;
            ans = b;
            i = c;
        }
        return {ret, ans, i};
    }
};

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    ll x; cin>>x;
    Node *root = new Node(x, 0);
    for (i=1;i<n;i++) {
        cin>>x;
        Node *cur = root;
        while (true) {
            if (cur->data < x) {
                if (cur->r) cur = cur->r;
                else {
                    cur->r = new Node(x, i);
                    break;
                }
            }
            else {
                if (cur->l) cur = cur->l;
                else {
                    cur->l = new Node(x, i);
                    break;
                }
            }
        }
    }
    root->dfs1();
    auto [ret, ans, idx] = root->dfs2();
    cout<<"Flock #"<<tc<<": ";
    cout<<ans<<endl<<endl;
    delete root;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}

