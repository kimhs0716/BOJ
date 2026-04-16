#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, m, k, t;
int**** board;
bool check(int w, int x, int y, int z, int size) {
	for (int a = 0; a < size; a++) {
		if (a + w >= n) break;
		for (int b = 0; b < size; b++) {
			if (b + x >= m) break;
			for (int c = 0; c < size; c++) {
				if (c + y >= k) break;
				for (int d = 0; d < size; d++) {
					if (d + z >= t) break;
					if (board[a + w][b + x][c + y][d + z] == 1) return false;
				}
			}
		}
	}
	return true;
}

int _min(int a, int b, int c, int d) {
	return min<int>(min<int>(a, b), min<int>(c, d));
}

int main() {
	cin >> n >> m >> k >> t;
	board = new int*** [n];
	for (int w = 0; w < n; w++) {
		board[w] = new int** [m];
		for (int x = 0; x < m; x++) {
			board[w][x] = new int* [k];
			for (int y = 0; y < k; y++) {
				board[w][x][y] = new int[t];
				for (int i = 0; i < t; i++) scanf("%d", board[w][x][y] + i);
			}
		}
	}

	for (int size = _min(n, m, k, t); size >= 0; size--) {
		for (int w = 0; w <= n - size; w++) {
			for (int x = 0; x <= m - size; x++) {
				for (int y = 0; y <= k - size; y++) {
					for (int z = 0; z <= t - size; z++) {
						if (check(w, x, y, z, size)) {
							printf("%d\n", size);
							return 0;
						}
					}
				}
			}
		}
	}

	return 0;
}