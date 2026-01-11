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

void preprocess() {
    ll i, j;
}

struct Node {
    ll cnt;
    array<Node*, 26> nxt;
    bool is_terminal;
    Node() {
        cnt = 0;
        fill(nxt.begin(), nxt.end(), nullptr);
        is_terminal = false;
    }
    ~Node() {
        for (auto &x: nxt) delete x;
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
    void add_string(string &s) {
        Node *cur = root;
        for (auto ch: s) {
            ch -= 'a';
            if (!cur->nxt[ch]) {
                cur->nxt[ch] = new Node;
                cur->cnt++;
            }
            cur = cur->nxt[ch];
        }
        cur->is_terminal = true;
    }
    ll dfs(Node *cur, ll depth) {
        ll ret = 0;
        if (cur->is_terminal) ret += depth;
        for (auto &x: cur->nxt) {
            if (x) ret += dfs(x, depth + (cur->cnt!=1 || cur->is_terminal));
        }
        return ret;
    }
    ll solve() {
        ll ret = 0;
        for (auto &x: root->nxt) {
            if (x) ret += dfs(x, 1);
        }
        return ret;
    }
};

void solve(ll tc) {
    ll i, j;
    ll n;
    while (cin>>n) {
        Trie trie;
        for (i=0;i<n;i++) {
            string s; cin>>s;
            trie.add_string(s);
        }
        cout<<fixed<<setprecision(2);
        cout<<(ld)trie.solve()/n<<endl;
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
