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
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
typedef struct {
	int x, y;
} Pos;
int main() {
	FASTIO;
	int n, m; cin >> n >> m;
	vvi original_board(n, vi(m));
	vvi board;
	vector<Pos> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> original_board[i][j];
			if (original_board[i][j] == 2) virus.push_back({ j, i });
		}
	}
	int M = 0;
	for (int i = 0; i < n * m; i++) {
		if (original_board[i / m][i % m] != 0) continue;
		original_board[i / m][i % m] = 1;
		for (int j = i + 1; j < n * m; j++) {
			if (original_board[j / m][j % m] != 0) continue;
			original_board[j / m][j % m] = 1;
			for (int k = j + 1; k < n * m; k++) {
				if (original_board[k / m][k % m] != 0) continue;
				original_board[k / m][k % m] = 1;
				board = original_board;
				queue<Pos> new_virus;
				for (auto p : virus) new_virus.push(p);
				while (!new_virus.empty()) {
					//cout << "===== #[DEBUG] =====\n";
					//cout << i << ' ' << j << ' ' << k << endl;
					//for (int i = 0; i < n; i++) {
					//	for (int j = 0; j < m; j++) {
					//		cout << board[i][j] << ' ';
					//	}
					//	cout << endl;
					//}
					//cout << "====================\n";
					int s = new_virus.size();
					while (s--) {
						Pos cur = new_virus.front();
						new_virus.pop();
						for (int i = 0; i < 4; i++) {
							int nx = cur.x + dx[i];
							int ny = cur.y + dy[i];
							if (0 <= nx && nx < m && 0 <= ny && ny < n && \
								board[ny][nx] == 0) {
								board[ny][nx] = 2;
								new_virus.push({ nx, ny });
							}
						}
					}
				}
				int ans = 0;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (board[i][j] == 0) ans++;
					}
				}
				M = max<int>(M, ans);
				//cout << "===== #[DEBUG] =====\n";
				//cout << i << ' ' << j << ' ' << k << ' ' << ans << endl;
				//for (int i = 0; i < n; i++) {
				//	for (int j = 0; j < m; j++) {
				//		cout << board[i][j] << ' ';
				//	}
				//	cout << endl;
				//}
				//cout << "====================\n";
				original_board[k / m][k % m] = 0;
			}
			original_board[j / m][j % m] = 0;
		}
		original_board[i / m][i % m] = 0;
	}
	cout << M << endl;

	return 0;
}
