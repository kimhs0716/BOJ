#include <iostream>
#include <vector>
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

typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int solve(vvi &arr, vvi &dp, int r, int c, int n) {
	if (dp[r][c] != 0) return dp[r][c];
	int M = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= n) continue;
		if (nc < 0 || nc >= n) continue;
		if (arr[r][c] >= arr[nr][nc]) continue;
		M = max<int>(M, solve(arr, dp, nr, nc, n));
	}
	return dp[r][c] = M + 1;
}

int main() {
	FASTIO;
	
	int n; cin >> n;
	vvi arr(n, vi(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vvi dp(n, vi(n));

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max<int>(ans, solve(arr, dp, i, j, n));
		}
	}

	cout << ans << endl;

/*	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
*/

	return 0;
}