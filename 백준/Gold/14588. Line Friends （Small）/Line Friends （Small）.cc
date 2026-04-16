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

vvl floyd(ll n, vector<vector<pll>>& adj){
    bool cycle = 0;
    vvl dis(n,vector<ll>(n, INF));
    for (ll i=0;i<n;++i) dis[i][i] = 0;

    for (ll u=0;u<n;++u)
        for (auto& [v,w]:adj[u])
            dis[u][v]=min(dis[u][v],w); //multi-edges?
    for (ll k=0;k<n;++k)
        for (ll i=0;i<n;++i)
            for (ll j=0;j<n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for (ll k=0;k<n;++k) // Check negative cycle
        for (ll i=0;i<n;++i)
            for (ll j=0;j<n;++j)
                if (dis[i][j]>dis[i][k]+dis[k][j]) cycle=1;
    return dis;
}


void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    vvp adj(n);
    vector<tlll> arr(n<<1);
    for (i=0;i<n;i++) {
        ll s, e; cin>>s>>e;
        arr[i<<1] = {s, 0, i};
        arr[i<<1|1] = {e, 1, i};
    }
    sort(arr.begin(), arr.end());
    unordered_set<ll> cur;
    bool updated = false;
    for (auto &[pos, type, idx] : arr) {
        if (type==0) {
            cur.insert(idx);
            updated = false;
        }
        else {
            if (updated==false) {
                for (auto it=cur.begin(); it!=cur.end(); it++) {
                    for (auto it2=next(it); it2!=cur.end(); it2++) {
                        adj[*it].push_back({*it2, 1});
                        adj[*it2].push_back({*it, 1});
                    }
                }
                updated = true;
            }
            cur.erase(idx);
        }
    }

    vvl dist = floyd(n, adj);

    ll q; cin>>q;
    while (q--) {
        ll u, v; cin>>u>>v;
        ll d = dist[u-1][v-1];
        if (d==INF) d = -1;
        cout<<d<<endl;
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