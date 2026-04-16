#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    // freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

typedef struct {
    int r, c;
    int time;
} elem;

int main() {
    FASTIO;
    _init();

    int tc; cin >> tc;
    while (tc--) {
        bool end = false;
        int r, c; cin >> c >> r;
        vector<vi> arr(r, vi(c));
        vector<pii> fires;
        pii start;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch; cin >> ch;
                if (ch == '#') arr[i][j] = 0;
                else if (ch == '.') arr[i][j] = 1;
                else if (ch == '@') {
                    start = { i, j };
                    arr[i][j] = 1;
                }
                else if (ch == '*') {
                    fires.push_back({ i, j });
                    arr[i][j] = 2;
                }
            }
        }


        int cur = -1;
        queue<elem> q;
        q.push({ start.first, start.second, 0 });
        set<pii> visited;
        visited.insert(start);
        while (!q.empty()) {
            elem item = q.front();
            //cout << item.r << ", " << item.c << ", " << item.time << endl;
            q.pop();
            if (item.time != cur) {
                cur++;
                vector<pii> new_fires;
                for (auto p : fires) {
                    for (int i = 0; i < 4; i++) {
                        int nr = p.first + dr[i];
                        int nc = p.second + dc[i];
                        if (nr < 0 || r <= nr) continue;
                        if (nc < 0 || c <= nc) continue;
                        if (arr[nr][nc] == 1) {
                            arr[nr][nc] = 2;
                            new_fires.push_back({ nr, nc });
                        }
                    }
                }
                fires = new_fires;
                //cout << "===== " << cur << " =====\n";
                //for (int i = 0; i < r; i++) {
                //    for (int j = 0; j < c; j++) {
                //        cout << arr[i][j] << ' ';
                //    }
                //    cout << endl;
                //}
            }
            for (int i = 0; i < 4; i++) {
                int nr = item.r + dr[i];
                int nc = item.c + dc[i];
                bool flag = false;
                if (nr < 0 || r <= nr) flag = true;
                if (nc < 0 || c <= nc) flag = true;
                if (flag) {
                    cout << item.time + 1 << endl;
                    end = true;
                    break;
                }
                if (arr[nr][nc] != 1) continue;
                if (visited.find({ nr, nc }) != visited.end()) {
                    continue;
                }
                visited.insert({ nr, nc });
                q.push({ nr, nc, item.time + 1 });
            }
            if (end) break;
        }
        if (end) continue;
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
