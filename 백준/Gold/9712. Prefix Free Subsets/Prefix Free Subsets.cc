#include <bits/stdc++.h>
#pragma GCC optimize ("O0,unroll-loops")
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

constexpr ll S = -1e8;
constexpr ll E = 1e8-1;

struct Node {
    ll is_leaf, dp, sz;
    Node *ch[26];
    Node() {
        is_leaf = 0;
        dp = 0;
        fill(ch, ch+26, nullptr);
    }
    ~Node() {
        for (auto x: ch)
            delete x;
    }
} *root;

void preprocess() {
    ll i, j, k;
}

void solve(ll tc) {
    ll i, j;
    root = new Node;
    ll n; cin>>n;
    while (n--) {
        string s; cin>>s;
        Node *cur = root;
        for (auto c: s) {
            if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node, cur->sz++;
            cur = cur->ch[c-'a'];
        }
        cur->is_leaf = 1;
    }
    function<ll(Node*)> dfs = [&dfs](Node *cur) -> ll {
        cur->dp = 1;
        for (auto x: cur->ch) {
            if (x) {
                dfs(x);
                cur->dp *= x->dp;
            }
        }
        cur->dp += cur->is_leaf;
        return cur->dp;
    };
    dfs(root);
    cout<<"Case #"<<tc<<": ";
    cout<<root->dp<<endl;
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

