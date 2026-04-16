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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ll MAX = 300'001;

// Usage :
// Constructor1 : BipartiteGraph bg(Lsize, Rsize); bg.add_edge(l_node, r_node);
// Constructor2 : BipartiteGraph bㄹg(vvl Adj);
// Maximum matching : bg.maximum_matching();
// O(E*sqrt(V))
struct BipartiteGraph {
    ll n; vl color; vvl adj;
    bool is_bipartite = true;
    ll leftSz, rightSz;
    vl leftNodes, rightNodes;   // partition idx → original idx
    vl leftId, rightId;         // original idx → partition idx
    vvl adjL;                   // left index → [right indices...]
    // maximum matching
    ll matching, distNil, INF = 1e10;
    vl pairL, pairR, dist;

    // 엣지를 바로 입력
    BipartiteGraph(ll L, ll R)
        : leftSz(L), rightSz(R), adjL(L) {}

    void add_edge(ll l, ll r) {
        adjL[l].emplace_back(r);
    }

    void erase_edge(ll ln, ll rn) {  // adjL 정렬 후 사용
        ll l = leftId[ln], r = rightId[rn];
        adjL[l].erase(lower_bound(adjL[l].begin(), adjL[l].end(), r));
    }

    // 일반 그래프 → 이분 그래프 변환
    BipartiteGraph(const vvl& G)
      : n(G.size()), adj(G), color(n, 0)
    {
        for (ll i=0; i<n; ++i) {    // 0-based index
            if (color[i] == 0 && !bfs_color(i)) {
                is_bipartite = false;
                return;
            }
        }
        build_bipartite();     // 좌우 파티션 노드 분리, 매핑, 인접 리스트 생성
    }

    bool bfs_color(ll s) {
        queue<ll> q;
        color[s] = 1;
        q.push(s);
        while (!q.empty()) {
            ll node = q.front(); q.pop();
            for (auto& nxt : adj[node]) {
                if (color[nxt] == 0) {
                    color[nxt] = -color[node];
                    q.push(nxt);
                } else if (color[nxt] == color[node])
                    return false;
            }
        }
        return true;
    }

    void build_bipartite() {
        leftId.assign(n, -1);
        rightId.assign(n, -1);
        for (ll i=0; i<n; ++i) {
            if (color[i] == 1) {
                leftId[i] = leftNodes.size();
                leftNodes.push_back(i);
            } else {
                rightId[i] = rightNodes.size();
                rightNodes.push_back(i);
            }
        }
        leftSz = leftNodes.size();
        rightSz = rightNodes.size();
        adjL.assign(leftSz, {});
        for (ll l=0; l<leftSz; ++l)
            for (auto& r : adj[leftNodes[l]])
                adjL[l].emplace_back(rightId[r]);
    }

    // maximum matching: Hopcroft-Karp
    ll max_matching() {
        matching = 0;
        pairL.assign(leftSz, -1);
        pairR.assign(rightSz, -1);
        dist.assign(leftSz, 0);
        while (bfs_HK())    // augmenting path 존재하는 동안 반복
            for (ll l=0; l<leftSz; ++l)
                if (pairL[l]==-1 && dfs_HK(l))
                    matching++;
        return matching;
    }

    bool bfs_HK() {    // 가장 짧은 augmenting path 찾음
        queue<ll> q;
        for (ll l=0; l<leftSz; l++) {
            if (pairL[l] == -1) {
                dist[l] = 0;
                q.emplace(l);
            } else dist[l] = INF;
        }
        distNil = INF;
        while (!q.empty()) {
            ll l = q.front(); q.pop();
            if (dist[l] < distNil) {
                for (auto& r : adjL[l]) {
                    ll pl = pairR[r];
                    if (pl != -1) {
                        if (dist[pl] == INF) {
                            dist[pl] = dist[l] + 1;
                            q.emplace(pl);
                        }
                    } else distNil = dist[l] + 1;
                }
            }
        }
        return distNil != INF;
    }

    bool dfs_HK(ll l) {
        for (ll r : adjL[l]) {
            ll pl = pairR[r];
            if (pl==-1 || (dist[pl]==dist[l]+1 && dfs_HK(pl))) {
                pairL[l] = r;
                pairR[r] = l;
                return true;
            }
        }
        dist[l] = INF;
        return false;
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl even, odd;
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        if (x&1) odd.push_back(x);
        else even.push_back(x);
    }
    ll m=odd.size(); n=even.size();
    BipartiteGraph bg(n, m);
    for (i=0;i<n;i++)
        for (j=0;j<m;j++) {
            if (gcd(even[i], odd[j])!=1) continue;
            ll t = sqrtl(even[i]*even[i] + odd[j]*odd[j]);
            if (t*t == even[i]*even[i] + odd[j]*odd[j]) bg.add_edge(i, j);
        }
    cout<<bg.max_matching()<<endl;
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

