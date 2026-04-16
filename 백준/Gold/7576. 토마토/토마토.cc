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
#include <cassert>

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
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 1'000'000'001;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

using element = struct {
    int r, c, time;
};

bool check(vector<vi> &arr) {
    for (auto &i: arr) {
        for (auto &j: i) {
            if (j == 0) return false;
        }
    }
    return true;
}

int main() {
    FASTIO;
    _init();


    queue<element> q;
    int c, r; cin >> c >> r;
    vector<vi> arr(r, vi(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.emplace(i, j, 0);
            }
        }
    }

    int ans = 0;
    while (true) {
        int cnt = 0;
        int current_time = q.front().time;
        ans = current_time;
        while (!q.empty() && q.front().time == current_time) {
            element item = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = item.r + dr[i];
                int nc = item.c + dc[i];
                if (nr < 0 || nr >= r) continue;
                if (nc < 0 || nc >= c) continue;
                if (arr[nr][nc] != 0) continue;
                arr[nr][nc] = 1;
                q.emplace(nr, nc, current_time + 1);
                cnt++;
            }
        }
        if (cnt == 0) break;
        if (q.empty()) break;
    }

    if (check(arr)) cout << ans << endl;
    else cout << "-1\n";

    return 0;
}
