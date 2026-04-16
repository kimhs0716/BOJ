#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

void setup() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

pll f(vvl &adj, vl &color, ll cur, ll cur_color) {
    pll ret={1, 0};
    if (cur_color) ret={0, 1};
    for (ll nxt: adj[cur]) {
        if (color[nxt]==-1) {
            color[nxt]=!cur_color;
            pll tmp=f(adj, color, nxt, !cur_color);
            if (tmp.first==-1) return {-1, -1};
            ret.first += tmp.first;
            ret.second += tmp.second;
        }
        else if (color[nxt]==cur_color) return {-1, -1};
    }
    return ret;
}

void solve(ll tc) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vvl adj(n+1);
    for (i=0;i<m;i++) {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vl color(n+1, -1);
    vector<pll> p;
    for (i=1;i<=n;i++) {
        if (color[i]==-1) {
            color[i]=0;
            pll ret=f(adj, color, i, 0);
            if (ret.first==-1) {
                cout<<"-1\n";
                return;
            }
            if (ret.first>ret.second) swap(ret.first, ret.second);
            p.push_back(ret);
            // cout<<ret.first<<' '<<ret.second<<endl;
        }
    }
    vl arr;
    for (auto x: p) arr.push_back(x.second-x.first);
    ll sum=accumulate(arr.begin(), arr.end(), 0LL);
    vector<char> dp(sum+1, 0);
    dp[0] = 1;
    for (ll diff : arr) {
        for (j = sum; j >= diff; --j) {
            if (dp[j-diff]) dp[j] = 1;
        }
    }
    ll best = INF;
    for (ll x = 0; x <= sum; ++x) {
        if (dp[x]) {
            ll d = abs(sum - 2*x);
            best = min(best, d);
        }
    }
    ll answer = (n + best) / 2;
    cout << answer << '\n';
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