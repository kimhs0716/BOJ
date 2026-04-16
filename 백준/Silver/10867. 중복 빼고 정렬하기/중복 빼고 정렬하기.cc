#include <iostream>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
	FASTIO;

	bool arr[2001];
	int n; cin >> n;
	fill(arr, arr + 2001, 0);

	while (n --> 0) {
		int a; cin >> a;
		arr[a + 1000] = 1;
	}

	for (int i = 0; i < 2001; i++) {
		if (arr[i]) cout << i - 1000 << ' ';
	}
	cout << endl;

	return 0;
}