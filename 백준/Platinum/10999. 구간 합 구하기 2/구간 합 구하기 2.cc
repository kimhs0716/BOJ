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
    Node *p, *l, *r;
    ll key, val, sum, sz, lazy;
    Node(ll key, ll val) : key(key), val(val), sum(val) {
        sz = 1;
        lazy = 0;
        p = l = r = nullptr;
    }
};

struct SplayTree {
    Node *root;

    SplayTree() {
        root = nullptr;
    }

    void push(Node *x) {
        if (!x || !x->lazy) return;
        x->val += x->lazy;
        if (x->l) {
            x->l->lazy += x->lazy;
            x->l->sum += x->lazy * x->l->sz;
        }
        if (x->r) {
            x->r->lazy += x->lazy;
            x->r->sum += x->lazy * x->r->sz;
        }
        x->lazy = 0;
    }

    void update(Node *x) {
        push(x);
        x->sum = x->val;
        x->sz = 1;
        if (x->l) {
            x->sum += x->l->sum;
            x->sz += x->l->sz;
        }
        if (x->r) {
            x->sum += x->r->sum;
            x->sz += x->r->sz;
        }
    }

    void rotate(Node *x) {
        Node *p = x->p, *b = nullptr;
        if (!p) return;
        push(p);
        push(x);
        if (x == p->l) {
            p->l = b = x->r;
            x->r = p;
        }
        else {
            p->r = b = x->l;
            x->l = p;
        }
        x->p = p->p;
        p->p = x;
        if (b) b->p = p;
        if (x->p) {
            if (p == x->p->l) x->p->l = x;
            else x->p->r = x;
        }
        else root = x;
        update(p);
        update(x);
    }

    void splay(Node *x, Node *g = nullptr) {
        while (x->p != g) {
            Node *p = x->p;
            if (p->p == g) { // zig step
                rotate(x);
                break;
            }
            Node *pp = p->p;
            if ((p->l==x) == (pp->l==p)) { // zig-zig step
                rotate(p); rotate(x);
            }
            else { // zig-zag step
                rotate(x); rotate(x);
            }
        }
        if (!g) root = x;
    }

    void insert(ll key, ll val) {
        Node *p = root;
        if (!p) { // empty tree
            Node *x = new Node(key, val);
            root = x;
            return;
        }
        while (true) {
            if (key == p->key) return;
            if (key < p->key) {
                if (!p->l) break;
                p = p->l;
            }
            else {
                if (!p->r) break;
                p = p->r;
            }
        }
        Node *x = new Node(key, val);
        x->p = p;
        if (p->key > x->key) p->l = x;
        else p->r = x;
        splay(x);
    }

    bool find(ll key) { // find and splay
        Node *p = root;
        if (!p) return false;
        while (p) {
            if (key == p->key) break;
            if (key < p->key) {
                if (!p->l) break;
                p = p->l;
            }
            else {
                if (!p->r) break;
                p = p->r;
            }
        }
        splay(p);
        return key == p->key;
    }

    void del(ll key) {
        if (!find(key)) return;
        Node *p = root;
        if (p->l && p->r) { // root has two child nodes
            root = p->l; // left child is new root node
            root->p = nullptr;
            // find maximum child of new root
            Node *x = root;
            while (x->r) x = x->r;
            splay(x);
            root->r = p->r;
            p->r->p = root;
            update(root);
            delete p;
            return;
        }
        if (p->l) { // root only has left child
            root = p->l;
            root->p = nullptr;
            update(root);
            delete p;
            return;
        }
        if (p->r) { // root only has right child
            root = p->r;
            root->p = nullptr;
            update(root);
            delete p;
            return;
        }
        // root has no child node
        delete p;
        root = nullptr;
    }

    void kth(ll k) { // splay kth node, 0-based
        Node *x = root;
        while (true) {
            push(x);
            while (x->l && x->l->sz > k) {
                x = x->l;
            }
            if (x->l) k -= x->l->sz;
            if (!k--) break;
            x = x->r;
        }
        push(x);
        splay(x);
    }

    Node *gather(ll s, ll e) {
        kth(e+1);
        auto temp = root;
        kth(s-1);
        splay(temp, root);
        return root->r->l;
    }
};

void solve(ll tc){
    ll i, j, k;
    ll n, q, qq; cin>>n>>q>>qq;
    SplayTree tree;
    tree.insert(0, 0);
    tree.insert(n+1, 0);
    for (i=1;i<=n;i++) {
        ll x; cin>>x;
        tree.insert(i, x);
    }
    q += qq;
    while (q--) {
        ll a, b, c, d; cin>>a>>b>>c;
        if (a==1) { // add d to [b..c]
            cin>>d;
            auto x = tree.gather(b, c);
            x->lazy += d;
            x->sum += d * x->sz;
        }
        else { // print sum of [b..c]
            auto x = tree.gather(b, c);
            tree.update(x);
            cout<<x->sum<<endl;
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
