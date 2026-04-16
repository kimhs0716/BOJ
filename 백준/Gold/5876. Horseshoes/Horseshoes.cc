#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> board;
bool vis[5][5];
int best = 0;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int L, int R, bool switched) {
    if (switched && L == R)                // 완전히 균형 잡힌 순간
        best = max(best, L + R);

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny])
            continue;

        char c = board[nx][ny];
        if (!switched) {                   // 아직 '(' 구간
            if (c == '(') {
                vis[nx][ny] = true;
                dfs(nx, ny, L + 1, R, false);
                vis[nx][ny] = false;
            } else {                       // 처음 ')' 을 만남 → 전환
                if (R + 1 <= L) {
                    vis[nx][ny] = true;
                    dfs(nx, ny, L, R + 1, true);
                    vis[nx][ny] = false;
                }
            }
        } else {                           // 이미 ')' 구간
            if (c == ')' && R + 1 <= L) {
                vis[nx][ny] = true;
                dfs(nx, ny, L, R + 1, true);
                vis[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N)) return 0;
    board.resize(N);
    for (string& row : board) cin >> row;

    if (board[0][0] != '(') {              // 시작이 ')' 이면 불가능
        cout << 0 << '\n';
        return 0;
    }

    memset(vis, 0, sizeof(vis));
    vis[0][0] = true;
    dfs(0, 0, 1, 0, false);               // '(' 하나 집은 상태로 시작

    cout << best << '\n';
    return 0;
}
