#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

pii backward(int r, int c, int d) {
	if (d == 0) return pii(r + 1, c);
	else if (d == 1) return pii(r, c - 1);
	else if (d == 2) return pii(r - 1, c);
	return pii(r, c + 1);
}

pii foward(int r, int c, int d) {
	if (d == 0) return pii(r - 1, c);
	else if (d == 1) return pii(r, c + 1);
	else if (d == 2) return pii(r + 1, c);
	return pii(r, c - 1);
}

int main() {
	int n, m; cin >> n >> m;
	int r, c; cin >> r >> c;
	int d; cin >> d; // direction, NESW 0123

	vvi arr(n, vi(m)); // 0: not cleaned, 1: wall, -1: cleaned
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	int ans = 0;
	while (true) {
		// [DEBUG]
#ifdef debug
		cout << "=============================\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (r == i && c == j) cout << "  R";
				else printf("%3d", arr[i][j]);
			}
			cout << endl;
		}
		cout << "ans: " << ans << ", d: " << d << endl << "=============================\n";
#endif debug

		if (arr[r][c] == 0) ans++, arr[r][c] = -1;
		bool cleaned = true;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < m && arr[nr][nc] == 0) {
				cleaned = false;
				break;
			}
		}
		if (cleaned) {
			pii next = backward(r, c, d);
			int nr = next.first;
			int nc = next.second;
			if (0 <= nr && nr < n && 0 <= nc && nc < m) {
				if (arr[nr][nc] == 1) break;
				else {
					r = nr, c = nc;
					continue;
				}
			}
			else break;
		}
		else {
			d = (d + 3) % 4;
			pii next = foward(r, c, d);
			int nr = next.first;
			int nc = next.second;
			if (0 <= nr && nr < n && 0 <= nc && nc < m) {
				if (arr[nr][nc] == 0) {
					r = nr, c = nc;
				}
			}
			else continue;
		}
	}

	cout << ans << endl;

	return 0;
}
