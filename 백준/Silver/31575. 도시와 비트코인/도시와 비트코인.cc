#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef struct {
	int r, c;
	int depth;
} node;

int dr[] = { 1, 0 };
int dc[] = { 0, 1 };
vvi board;
vvi visited;

int main() {
	FASTIO;
	
	int r, c; cin >> c >> r;
	board = vvi(r, vi(c));
	visited = board;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cin >> board[i][j];
	}
	
	queue<node> q;
	q.push({ 0, 0, 0 });

	bool flag = false;

	while (!q.empty()) {
		node item = q.front();
		q.pop();

		if (item.r == r - 1 && item.c == c - 1) {
			flag = true;
			break;
		}

		for (int i = 0; i < 2; i++) {
			int nc = item.c + dc[i], nr = item.r + dr[i];
			if (nc < 0 || nc >= c) continue;
			if (nr < 0 || nr >= r) continue;
			if (board[nr][nc] == 0) continue;
			if (visited[nr][nc]) continue;
			visited[nr][nc] = true;
			q.push({ nr, nc, item.depth + 1 });
		}		
	}

	if (flag) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}