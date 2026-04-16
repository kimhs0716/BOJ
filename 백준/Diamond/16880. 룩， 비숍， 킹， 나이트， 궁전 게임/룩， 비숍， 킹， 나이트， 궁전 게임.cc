#include <iostream>
#include <vector>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using vi = vector<int>;

int g(int r, int c, char type) {
	if (type == 'P') {
		return ((r / 3) ^ (c / 3)) * 3 + (r + c) % 3;
	}
	else if (type == 'R') {
		return r ^ c;
	}
	else if (type == 'B') {
		return min<int>(r, c);
	}
	else if (type == 'K') {
		if (r > c) return g(c, r, type);
		if (r == c) return (r % 2) * 2;
		if (r % 2 == 0) return (c - r) % 2;
		return (c - r) % 2 + 2;
	}
	else if (type == 'N') {
		if (r > c) return g(c, r, type);
		if (r == c) return r % 3 == 2;
		if (r % 3 == 2 && c - r == 1) return 1;
		return r % 3;
	}
}

int main() {
	FASTIO;

	int n; cin >> n;
	int x = 0;
	while (n--) {
		int r, c; char t;
		cin >> r >> c >> t;
		x ^= g(r, c, t);
	}

	cout << (x ? "koosaga" : "cubelover") << endl;

	return 0;
}