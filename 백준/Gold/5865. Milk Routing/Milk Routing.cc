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
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
constexpr ll MAX = 1'000'000;

void preprocess() {
    ll i, j, k;
}

//Usage: vl distance = dijk(V, start, adj);
//O(ElogV)
vd dijk(ll n, ll s, vector<vector<pair<ll, ld>>>& adj){
    const ll INF = 1e18;
    vd dis(n,INF);
    vector<bool> visit(n, false);
    priority_queue<pair<ll, ld>, vector<pair<ll, ld>>, greater<pair<ll, ld>> > q; // pair(dist, v)
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty()){
        while (!q.empty() && visit[q.top().second]) q.pop();
        if (q.empty()) break;
        ll next=q.top().second; q.pop();
        visit[next]=1;
        for (ll i=0;i<adj[next].size();++i)
            if (dis[adj[next][i].first] > dis[next] + adj[next][i].second){
                dis[adj[next][i].first] = dis[next] + adj[next][i].second;
                q.push({dis[adj[next][i].first], adj[next][i].first});}}
    for(ll i=0;i<n;i++) if(dis[i]==INF) dis[i]=-1;
    return dis;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m, x; cin>>n>>m>>x;
    vl left(m), right(m), delay(m), cap(m);
    for (i=0;i<m;i++) {
        cin>>left[i];
        cin>>right[i];
        cin>>delay[i];
        cin>>cap[i];
        left[i]--;
        right[i]--;
    }
    vl t = cap;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    ld ans=INF;
    for (ll bt : t) {
        vector<vector<pair<ll, ld>>> edges(n);
        for (i=0;i<m;i++) {
            if (cap[i]>=bt) edges[left[i]].push_back({right[i], delay[i]});
            if (cap[i]>=bt) edges[right[i]].push_back({left[i], delay[i]});
        }
        vd dist = dijk(n, 0, edges);
        // cout<<bt<<' '<<dist<<endl;
        if (dist[n-1] != -1) ans = min(ans, dist[n-1] + (ld)x/bt);
        else break;
    }
    cout<<(ll)ans<<endl;
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