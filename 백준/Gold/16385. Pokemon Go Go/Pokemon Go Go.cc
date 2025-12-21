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

constexpr ll INF = (ll)4e18;

static inline ll manhattan(const pll& a, const pll& b) {
    return llabs(a.first - b.first) + llabs(a.second - b.second);
}

void preprocess() {}

void solve(ll testcase) {
    ll n; cin >> n;

    map<pll, int> idx;
    vector<pll> pos; 
    vector<ll> stopMask;
    unordered_map<string, int> pid;
    int P = 0;

    for (ll i = 0; i < n; i++) {
        ll r, c; string p;
        cin >> r >> c >> p;
        pll rc = {r, c};

        auto itp = pid.find(p);
        int id;
        if (itp == pid.end()) {
            id = P++;
            pid.emplace(p, id);
        } else id = itp->second;

        auto it = idx.find(rc);
        int idc;
        if (it == idx.end()) {
            idc = (int)pos.size();
            idx.emplace(rc, idc);
            pos.push_back(rc);
            stopMask.push_back(0);
        } else idc = it->second;

        stopMask[idc] |= (1LL << id);
    }

    ll ALL = (1LL << P) - 1;

    int S = (int)pos.size() + 1;
    vector<pll> nodes(S);
    vector<ll> pmask(S, 0);
    nodes[0] = {0, 0};
    for (int i = 1; i < S; i++) {
        nodes[i] = pos[i - 1];
        pmask[i] = stopMask[i - 1];
    }

    vvl dist(S, vl(S, 0));
    for (int i = 0; i < S; i++) {
        for (int j = i + 1; j < S; j++) {
            ll d = manhattan(nodes[i], nodes[j]);
            dist[i][j] = dist[j][i] = d;
        }
    }

    vvl dp(ALL + 1, vl(S, INF));
    dp[0][0] = 0;

    for (ll mask = 0; mask <= ALL; mask++) {
        for (int u = 0; u < S; u++) {
            ll cur = dp[mask][u];
            if (cur >= INF) continue;
            for (int v = 0; v < S; v++) {
                if (u == v) continue;
                ll nmask = mask | pmask[v];
                dp[nmask][v] = min(dp[nmask][v], cur + dist[u][v]);
            }
        }
    }

    ll ans = INF;
    for (int u = 0; u < S; u++) {
        ans = min(ans, dp[ALL][u] + dist[u][0]);
    }
    cout << ans << endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    for (ll i = 1; i <= testcase; i++) solve(i);
}
