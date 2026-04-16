#include <iostream>
#include <vector>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using vi = vector<int>;

int g(int r, int c) {
	return ((r / 3) ^ (c / 3)) * 3 + (r + c) % 3;
}

int main() {
	FASTIO;

	int n; cin >> n;
	int x = 0;
	while (n--) {
		int r, c; cin >> r >> c;
		x ^= g(r, c);
	}

	cout << (x ? "koosaga" : "cubelover") << endl;

	return 0;
}