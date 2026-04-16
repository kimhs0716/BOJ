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
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

//Usage: vl distance = dijk(V, start, adj);
//O(ElogV)
vl dijk(ll n, ll s, vector<vector<pll>>& adj){
    const ll INF = 1e18;
    vl dis(n,INF);
    vector<bool> visit(n, false);
    priority_queue<pll, vector<pll>, greater<pll> > q; // pair(dist, v)
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

void solve(ll tc){
    ll i, j;
    map<string, ll> name2idx;
    ll cnt=2;
    vector adj(2, vector<pll>());
    ll n; cin>>n;
    string src, dst; cin>>src>>dst;
    name2idx[src] = 0;
    name2idx[dst] = 1;
    while (n--) {
        string s1, s2; ll w;
        cin>>s1>>s2>>w;
        if (!name2idx.contains(s1)) {
            name2idx[s1] = cnt++;
        }
        if (!name2idx.contains(s2)) {
            name2idx[s2] = cnt++;
        }
        adj.resize(cnt);
        adj[name2idx[s1]].push_back({name2idx[s2], w});
        adj[name2idx[s2]].push_back({name2idx[s1], w});
    }
    cout<<src<<' '<<dst<<' ';
    cout<<dijk(cnt, 0, adj)[1]<<endl;
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