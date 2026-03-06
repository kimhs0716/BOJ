#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
            }
            cur->cnt++;
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

int solution(vector<string> words) {
    Trie trie;
    for (auto &w : words) trie.add_string(w);
    return (int)trie.solve();
}