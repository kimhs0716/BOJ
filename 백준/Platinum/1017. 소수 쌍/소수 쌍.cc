//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair
#include <set>
#include <queue>
#include <stack>
#include <map>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using pll = pair<ll, ll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1'000'001;

vector<vl> adj;
vl ones, others;
vl other2one;

bool dfs(int node, vl& visited_one, vl& visited_other) {
    // cout << "node: " << node << endl;
    for (int other: adj[node]) {
        if (other2one[other] == -1) {
            visited_other[other] = 1;
            other2one[other] = node;
            return true;
        }
        int nxt = other2one[other];
        if (visited_one[nxt]) continue;
        visited_one[nxt] = 1;
        other2one[other] = node;
        visited_other[other] = 1;
        if (dfs(nxt, visited_one, visited_other)) return true;
        // visited_other[other] = 0;
        other2one[other] = nxt;
        // visited_one[nxt] = 0;
    }
    return false;
}

bool isprime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    ll i = 3;
    while (i * i <= n) {
        if (n % i == 0) return false;
        i += 2;
    }
    return true;
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vl ans;

    int t; cin >> t;
    ones.push_back(t);
    for (int i = 1; i < n; i++) {
        int k; cin >> k;
        if ((t + k) % 2) others.push_back(k);
        else ones.push_back(k);
    }

    n = ones.size();
    int m = others.size();
    adj = vector<vl>(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isprime(ones[i] + others[j])) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i: adj[0]) {
        other2one = vl(m, -1);
        other2one[i] = 0;

        for (int j = 1; j < n; j++) {
            vl visited_one(n), visited_other(m);
            visited_one[0] = 1;
            visited_other[i] = 1;
            visited_one[j] = 1;
            dfs(j, visited_one, visited_other);
        }
        int cnt = 0;
        for (auto j: other2one) {
            if (j != -1) cnt++;
        }
        if (cnt == m && n == m) ans.push_back(others[i]);
        // for (auto j: other2one) {
        //     cout << j << ' ';
        // }
        // cout << endl;
    }

    if (!ans.empty()) {
        sort(ans.begin(), ans.end());
        for (auto i: ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    else cout << "-1\n";

    return 0;
}
