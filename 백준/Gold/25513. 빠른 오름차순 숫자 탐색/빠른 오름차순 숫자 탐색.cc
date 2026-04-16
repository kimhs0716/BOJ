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

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e10;
constexpr ll MAX = 65535;

void preprocess() {
    ll i, j, k;
}

//Usage: auto [negative cycle, distance]=floyd(V, adj);
//O(V^3)
vvl floyd(ll n, vvl& adj){
    vvl dis(n,vl(n, INF));
    for (ll i=0;i<n;++i) dis[i][i] = 0;

    for (ll u=0;u<n;++u)
        for (auto& v :adj[u])
            dis[u][v]=min(dis[u][v],1LL); //multi-edges?
    for (ll k=0;k<n;++k)
        for (ll i=0;i<n;++i)
            for (ll j=0;j<n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    return dis;
}


ll dr[] = {0, 1, 0, -1};
ll dc[] = {1, 0, -1, 0};
void solve(ll testcase) {
    ll i, j, k;
    vvl arr(5, vl(5)); cin>>arr;
    vl pos(6);
    vvl adj(25);
    for (i=0;i<25;i++) {
        ll r=i/5, c=i%5;
        if (arr[r][c] != -1) pos[arr[r][c]] = i;
        else continue;
        for (k=0;k<4;k++) {
            ll nr = r + dr[k];
            ll nc = c + dc[k];
            if (nr<0 || nr>=5) continue;
            if (nc<0 || nc>=5) continue;
            if (arr[nr][nc] != -1) {
                adj[i].push_back(nr*5+nc);
                adj[nr*5+nc].push_back(i);
            }
        }
    }
    vvl dis = floyd(25, adj);
    ll r, c; cin>>r>>c;
    ll ans = dis[r*5+c][pos[1]];
    ans += dis[pos[1]][pos[2]];
    ans += dis[pos[2]][pos[3]];
    ans += dis[pos[3]][pos[4]];
    ans += dis[pos[4]][pos[5]];
    ans += dis[pos[5]][pos[6]];
    cout<<(ans>=INF ? -1 : ans)<<endl;
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

