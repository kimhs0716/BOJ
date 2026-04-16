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
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

bool check(vvl &adj, ll bt) {
    ll n = adj.size();
    vl color(n, -1);
    queue<ll> q;

    auto bfs = [&](ll s)->bool{
        color[s]=0; q.push(s);
        while(q.size()){
            ll cur=q.front(); q.pop();
            for(ll nxt=0;nxt<n;nxt++){
                if (nxt==cur) continue;
                if (adj[cur][nxt] >= bt) continue;
                if (color[nxt]==-1){
                    color[nxt]=!color[cur];
                    q.push(nxt);
                }
                else if (color[nxt]==color[cur]){
                    return false;
                }
            }
        }
        return true;
    };

    for (ll i=0;i<n;i++) if (color[i]==-1) {
        if (!bfs(i)) return false;
    }
    return true;
}


void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vvl adj(n, vl(n));
    cin>>adj;
    if (n==3) {
        ll ans = 0;
        for (i=0;i<n;i++) for (j=i+1;j<n;j++) if (adj[i][j]>ans) ans=adj[i][j];
        cout<<ans<<endl;
        return;
    }
    ll lo=0, hi=1'000'001;
    while (lo+1<hi) {
        ll mid = (lo+hi)>>1;
        if (check(adj, mid)) lo=mid;
        else hi=mid-1;
    }
    if (check(adj, hi)) cout<<hi<<endl;
    else cout<<lo<<endl;
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