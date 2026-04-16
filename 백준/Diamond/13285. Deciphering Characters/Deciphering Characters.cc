#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")

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

void preprocess() {
    ll i, j;
}

struct Node {
    bool color;
    vector<Node*> children;

    void print(ll depth=0) {
        for (ll i=0;i<depth*4;i++) cout<<' ';
        cout<<children.size()<<endl;
        for (auto ch: children) ch->print(depth+1);
    }

    ull hash() {
        ull ret=color?0x12345679ULL:0x976543211ULL;
        vector<ull> t;
        for (auto ch: children) {
            t.push_back(ch->hash());
        }
        sort(t.begin(), t.end());
        for (auto x: t) {
            ret ^= x<<13;
            ret <<= 6;
            ret ^= x>>7;
            ret >>= 11;
            ret ^= x<<5;
            ret <<= 2;
        }
        return ret;
    }

    ~Node() {
        for (auto ch: children) delete ch;
    }
};

ll dr[] = {0, 1, 0, -1, 1, 1, -1, -1};
ll dc[] = {1, 0, -1, 0, 1, -1, 1, -1};

ll dfs(vvl &arr, vvl &vis, ll rr, ll cc, bool color, ll idx) {
    ll r=arr.size(), c=arr[0].size();
    ll t, par=-1;
    if (color) t=8;
    else t=4;

    for (ll i=0;i<t;i++) {
        ll nr=rr+dr[i], nc=cc+dc[i];
        if (nr<0 || r<=nr) continue;
        if (nc<0 || c<=nc) continue;
        if (vis[nr][nc]!=-1) {
            if (vis[nr][nc]!=idx) par=vis[nr][nc];
            continue;
        }
        if (arr[nr][nc] != color) continue;
        vis[nr][nc] = idx;
        ll p=dfs(arr, vis, nr, nc, color, idx);
        if (p!=-1) par=p;
    }

    return par;
}

Node* make_tree(vvl &arr, vvl &vis) {
    vector<Node*> ret;
    Node *root = new Node {0};
    ret.push_back(root);
    ll r=arr.size(), c=arr[0].size();
    ll idx=0;
    vis[0][0] = 0;
    dfs(arr, vis, 0, 0, arr[0][0], idx);
    for (ll i=0;i<r;i++) {
        for (ll j=0;j<c;j++) {
            if (vis[i][j]!=-1) continue;
            vis[i][j]=++idx;
            ll par=dfs(arr, vis, i, j, arr[i][j], idx);
            Node *n = new Node {(bool)arr[i][j]};
            ret[par]->children.push_back(n);
            ret.push_back(n);
        }
    }
    // for (auto &x: vis) {
    //     for (auto y: x) cout<<y<<' ';
    //     cout<<endl;
    // }
    return root;
}

void solve(ll tc){
    ll i, j;
    while (true) {
        ll r, c; cin>>r>>c;
        if (!r) break;
        vvl arr(r+2, vl(c+2)), vis(r+2, vl(c+2, -1));
        for (i=1;i<=r;i++) {
            string s; cin>>s;
            for (j=1;j<=c;j++) {
                arr[i][j] = s[j-1]=='#';
            }
        }
        auto root1=make_tree(arr, vis);
        // root1->print();
        // cout<<root1->hash()<<endl;

        cin>>r>>c;
        arr = vvl(r+2, vl(c+2)), vis = vvl(r+2, vl(c+2, -1));
        for (i=1;i<=r;i++) {
            string s; cin>>s;
            for (j=1;j<=c;j++) {
                arr[i][j] = s[j-1]=='#';
            }
        }
        auto root2=make_tree(arr, vis);
        // root2->print();
        // cout<<root2->hash()<<endl;
        if (root1->hash() == root2->hash()) cout<<"yes\n";
        else cout<<"no\n";
        delete root1;
        delete root2;
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