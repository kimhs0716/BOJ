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
    ll key, val, sz, lazy;
    Node(ll key, ll val) : key(key), val(val) {
        sz = 1;
        lazy = 0;
        p = l = r = nullptr;
    }
};

struct SplayTree {
    Node *root;
    Node *st[100005];
    ll top;

    SplayTree() {
        root = nullptr;
        top = 0;
    }

    void push(Node *x) {
        if (!x || !x->lazy) return;
        swap(x->l, x->r);
        if (x->l) {
            x->l->lazy ^= x->lazy;
        }
        if (x->r) {
            x->r->lazy ^= x->lazy;
        }
        x->lazy = 0;
    }

    void update(Node *x) {
        push(x);
        x->sz = 1;
        if (x->l) {
            x->sz += x->l->sz;
        }
        if (x->r) {
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
        for (auto y = x; y!=g; y=y->p) st[top++] = y;
        while (top) {
            push(st[--top]);
        }
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
                push(x);
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
    string s; cin>>s;
    ll n = s.size();
    SplayTree tree;
    tree.root = new Node(0, -1);
    auto cur = tree.root;
    for (i=0;i<n;i++) {
        auto x = new Node(i+1, s[i]);
        x->p = cur;
        cur->r = x;
        cur = x;
    }
    cur->r = new Node(n + 1, -1);
    cur->r->p = cur;
    cur = cur->r;
    while (cur) {
        tree.update(cur);
        cur = cur->p;
    }
    ll q; cin>>q;
    while (q--) {
        ll a, b, c; cin>>a>>b;
        if (a==1) {
            cin>>c;
            if (b==0) continue;
            auto x = tree.gather(1, c+1);
            x->lazy ^= 1;

            x = tree.gather(1, c-b+1);
            x->lazy ^= 1;

            x = tree.gather(c-b+2, c+1);
            x->lazy ^= 1;
        }
        else if (a==2) {
            cin>>c;
            if (c==n-1) continue;
            auto x = tree.gather(b+1, n);
            x->lazy ^= 1;

            x = tree.gather(b+1, n-c+b-1);
            x->lazy ^= 1;

            x = tree.gather(n-c+b, n);
            x->lazy ^= 1;
        }
        else {
            tree.kth(b+1);
            cout<<(char)tree.root->val<<endl;
        }
        // for (i=0;i<n;i++) {
        //     tree.kth(i+1);
        //     cout<<(char)tree.root->val<<'|';
        // }
        // cout<<endl;
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
