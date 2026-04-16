#include <iostream>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
	FASTIO;

	long long n; cin >> n;
	long long s = n * (n - 1) / 2;
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		s -= m;
	}
	cout << -s << endl;

	return 0;
}