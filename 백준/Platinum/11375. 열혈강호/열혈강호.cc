#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
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
ostream& operator<<(ostream &os, vector<T> &arr) {
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

// Usage: BipartiteMatching bm(leftV,rightV,graph);
//          ll ans = bm.max_matching; vl LtoR=bm.match; vl RtoL=bm.matched;
// O(E*sqrt(V))
// memo: vertex cover: (reached[0][left_node] == 0) || (reached[1][right_node] == 1)
struct BM {
    ll n, m, max_matching;
    vvl graph;
    vl matched, match, edgeview, level;
    vl reached[2];
    BM(ll n, ll m, vvl& graph) : n(n), m(m), graph(graph), matched(m,-1), match(n,-1) {
        max_matching = 0;
        while (assignLevel()) {
            edgeview.assign(n, 0);
            for (ll i = 0; i < n; i++)
                if (match[i]==-1)
                    max_matching += findpath(i);
        }
    }
    bool assignLevel(){
        bool reachable = false;
        level.assign(n,-1);
        reached[0].assign(n, 0);
        reached[1].assign(m, 0);
        queue<ll> q;
        for (ll i = 0; i < n; i++) {
            if (match[i] ==-1) {
                level[i] = 0;
                reached[0][i] = 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (auto adj : graph[cur]) {
                reached[1][adj] = 1;
                auto next = matched[adj];
                if (next ==-1) {
                    reachable = true;
                }
                else if (level[next] ==-1) {
                    level[next] = level[cur] + 1;
                    reached[0][next] = 1;
                    q.push(next);
                }
            }
        }
        return reachable;
    }
    ll findpath(ll node){
        for (ll &i = edgeview[node]; i < graph[node].size(); i++) {
            ll adj = graph[node][i];
            ll next = matched[adj];
            if (next >= 0 && level[next] != level[node] + 1) continue;
            if (next ==-1 || findpath(next)) {
                match[node] = adj;
                matched[adj] = node;
                return 1;
            }
        }
        return 0;
    };
};

void solve(ll testcase) {
    ll i, j;
    ll n, m; cin>>n>>m;
    vvl adj(n);
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        while (x--) {
            ll y; cin>>y;
            adj[i].push_back(y-1);
        }
    }
    BM bm(n, m, adj);
    cout<<bm.max_matching<<endl;
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