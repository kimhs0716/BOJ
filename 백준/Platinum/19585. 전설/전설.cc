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

struct Node {
    unordered_map<char, Node*> child;
    bool is_leaf;
    Node() : is_leaf(false) {}
    ~Node() {
        for (auto [ch, ptr] : child)
            delete ptr;
    }
};

struct Trie {
    Node *root;
    Trie() {
        root = new Node;
    }
    ~Trie() {
        delete root;
    }
    void add(string &s) {
        Node *cur = root;
        for (auto ch : s) {
            if (cur->child.count(ch)==0)
                cur->child[ch] = new Node;
            cur = cur->child[ch];
        }
        cur->is_leaf = true;
    }
    vl find(string &s) {
        vl ret;
        Node *cur = root;
        for (ll i=0;i<s.size();i++) {
            if (cur->child.count(s[i])==0)
                return ret;
            cur = cur->child[s[i]];
            if (cur->is_leaf)
                ret.push_back(i);
        }
        return ret;
    }
};

void solve(ll tc){
    ll i, j;
    ll n, m; cin>>n>>m;
    Trie trie;
    while (n--) {
        string s; cin>>s;
        trie.add(s);
    }
    unordered_set<string> name;
    while (m--) {
        string s; cin>>s;
        name.insert(s);
    }
    ll q; cin>>q;
    while (q--) {
        string s; cin>>s;
        vl res = trie.find(s);
        bool flag = false;
        for (ll x : res) {
            if (name.count(s.substr(x+1))) {
                flag = true;
                break;
            }
        }
        cout<<(flag ? "Yes" : "No")<<endl;
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
