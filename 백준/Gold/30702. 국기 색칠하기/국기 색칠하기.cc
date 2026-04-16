#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

void dfs(vector<string> &arr, int r, int c, char dst, char ch, vvi &visited) {
	arr[r][c] = dst;

	/*
	cout << r << ' ' << c << ' ' << ch << ' ' << dst << endl;
	for (auto s: arr) cout << s << endl;
	cout << "=====\n";
	for (auto i: visited) {
		for (auto j: i) cout << j << ' ';
		cout << endl;
	}
	cout << "====================\n";
	*/

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= arr.size()) continue;
		if (nc < 0 || nc >= arr[0].size()) continue;
		if (arr[nr][nc] != ch) continue;
		if (visited[nr][nc] == 1) continue;
		visited[nr][nc] = 1;
		dfs(arr, nr, nc, dst, ch, visited);
	}
}

int main() {
	FASTIO;
	
	int r, c; cin >> r >> c;
	vector<string> A(r), B(r);
	for (int i = 0; i < r; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < r; i++) {
		cin >> B[i];
	}

	vvi visited(r, vi(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == 0) {
				visited[i][j] = 1;
				dfs(A, i, j, B[i][j], A[i][j], visited);
			}
		}
	}

	// for (auto s: A) cout << s << endl;

	if (A == B) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}