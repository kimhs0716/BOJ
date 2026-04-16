#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    map<pll, ll> time;
    ll i, j, k;
    ll n; cin>>n;
    ll r=0, c=0;
    map<pll, set<pll>> adj;
    while (n--) {
        char dir; cin>>dir;
        ll pr=r, pc=c;
        if (dir=='N') r++;
        if (dir=='E') c++;
        if (dir=='W') c--;
        if (dir=='S') r--;
        adj[{pr, pc}].insert({r, c});
        adj[{r, c}].insert({pr, pc});
    }
    if (r==0 && c==0) {
        cout<<"0\n";
        return;
    }
    set<pll> visited;
    pll cur={0, 0};
    visited.insert(cur);
    queue<pll> q;
    q.push(cur);
    ll t=0;
    while (q.size()) {
        ll sz=q.size();
        for (i=0;i<sz;i++) {
            cur=q.front();
            q.pop();
            for (auto &[nr, nc]: adj[cur]) {
                if (r==nr && c==nc) {
                    cout<<t+1<<endl;
                    return;
                }
                if (visited.contains({nr, nc})) continue;
                visited.insert({nr, nc});
                q.push({nr, nc});
            }
        }
        t++;
    }
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