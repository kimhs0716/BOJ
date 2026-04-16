#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
class debugstream {
public:
	ostream& os;
	debugstream(ostream& os) :os(os) {}
	template <typename T>
	ostream& operator<<(const T& obj) {
		return os << "#[DEBUG]: " << obj;
	}
};
debugstream dout(cout);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef struct {
	int x, y;
} Pos;
bool cmp(const Pos& p1, const Pos& p2) {
	if (p1.y == p2.y) return p1.x < p2.x;
	return p1.y < p2.y;
}
bool operator<(const Pos& p1, const Pos& p2) {
	if (p1.y == p2.y) return p1.x < p2.x;
	return p1.y < p2.y;
}
bool operator==(const Pos& p1, const Pos& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}
bool operator!=(const Pos& p1, const Pos& p2) {
	return !(p1 == p2);
}
typedef struct {
	Pos p;
	int depth;
} node;
vvi board;
int __size = 2, t = 0;
int size_cnt = 0, n;
Pos cur;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool bfs() {
	node item = { cur, 0 };
	map<Pos, bool> visited;
	visited[cur] = 1;
	queue<node> q;
	q.push(item);
	bool found = 0;
	int dis = 2147483647;
	vector<Pos> targets;
	while (!q.empty()) {
		item = q.front();
		q.pop();
		if (found && item.depth > dis) {
			break;
		}
		if (cur != item.p && board[item.p.y][item.p.x] != 0 && board[item.p.y][item.p.x] < __size) {
			found = 1;
			targets.push_back(item.p);
			dis = item.depth;
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = item.p.x + dx[i];
				int ny = item.p.y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (board[ny][nx] <= __size && visited[{ nx, ny }] == false) {
						visited[{ nx, ny }] = true;
						q.push({ nx, ny, item.depth + 1 });
					}
				}
			}
		}
	}
	sort(targets.begin(), targets.end(), cmp);
	if (targets.size() == 0) {
		return 0;
	}
	t += dis;
	board[cur.y][cur.x] = 0;
	cur = targets[0];
	board[cur.y][cur.x] = 9;
	size_cnt++;
	if (size_cnt == __size) {
		__size++;
		size_cnt = 0;
	}
	return 1;
}
void debug() {
	cout << "===== #[DEBUG] =====\n";
	cout << "cur: (" << cur.x << ", " << cur.y << "), t: " << t << endl;
	cout << "size: " << __size << ", size_cnt: " << size_cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "====================\n";
}
int main() {
	FASTIO;
	cin >> n;
	board = vvi(n, vi(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) cur = { j, i };
		}
	}
	while (true) {
		bool result = bfs();
		if (result == false) break;
		//debug();
	}
	cout << t << endl;

	return 0;
}
