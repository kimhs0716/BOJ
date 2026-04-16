#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pii pair<int, int>
#define pib pair<int, bool>
using namespace std;
bool visited[100001];
bool fanclub[100001];
vector<vector<int>> adj(100001);
int n, m, s;
int main() {
    FASTIO;
    bool passed = false;
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    cin >> s;
    while (s--) {
        int a; cin >> a;
        fanclub[a] = 1;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (visited[c]) continue;
        visited[c] = true;
        if (fanclub[c]) continue;
        if (adj[c].size() == 0) {
            passed = true;
            break;
        }
        for (auto i : adj[c]) {
            if (!visited[i]) q.push(i);
        }
    }
    if (passed) cout << "yes\n";
    else cout << "Yes\n";
    return 0;
}