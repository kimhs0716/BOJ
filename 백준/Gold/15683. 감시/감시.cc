#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
	freopen("boj.in", "r", stdin);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;
using camera = struct {
	int r, c;
	int type;
};

void draw(vector<vi>& arr, int r, int c, int dir) {
	dir %= 4;
	int nr = r, nc = c;
	while (true) {
		if (dir == 0) nr--;
		else if (dir == 1) nc++;
		else if (dir == 2) nr++;
		else nc--;
		if (nr < 0 || nr >= arr.size()) return;
		if (nc < 0 || nc >= arr[0].size()) return;
		if (arr[nr][nc] == 6) return;
		arr[nr][nc] = -1;
	}
}

int check(vector<vi> arr, vector<camera>& cameras, vi& dirs) {
	int ans = 0;
	int n = arr.size(), m = arr[0].size();
	for (int i = 0; i < cameras.size(); i++) {
		camera c = cameras[i];
		int dir = dirs[i];
		draw(arr, c.r, c.c, dir);
		if (c.type == 5) draw(arr, c.r, c.c, dir + 1);
		if (c.type != 1 && c.type != 3) draw(arr, c.r, c.c, dir + 2);
		if (c.type != 1 && c.type != 2) draw(arr, c.r, c.c, dir + 3);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += arr[i][j] == 0;
		}
	}
	return ans;
}

int dfs(vector<vi>& arr, vector<camera>& cameras, vi& dirs, int depth) {
	// cout << "#[DEBUG] depth: " << depth << endl;
	if (depth == cameras.size()) return check(arr, cameras, dirs);
	int ans = numeric_limits<int>::max();
	for (int i = 0; i < 4; i++) {
		dirs[depth] = i;
		ans = min<int>(ans, dfs(arr, cameras, dirs, depth + 1));
	}
	return ans;
}

int main() {
	FASTIO;
	_init();

	int n, m; cin >> n >> m;
	vector<camera> cameras;
	vi dirs;
	vector<vi> arr(n, vi(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cameras.push_back({ i, j, arr[i][j] });
				dirs.push_back(0);
			}
		}
	}

	cout << dfs(arr, cameras, dirs, 0) << endl;

	return 0;
}
