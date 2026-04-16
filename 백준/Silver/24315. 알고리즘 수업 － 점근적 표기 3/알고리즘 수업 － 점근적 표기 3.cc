#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main() {
	int a1, a0, c1, c2, n0; cin >> a1 >> a0 >> c1 >> c2 >> n0;
	for (int i = n0; i <= 1000; i++) {
		if (c1 * i <= a1 * i + a0 && a1 * i + a0 <= c2 * i) continue;
		cout << '0' << endl;
		return 0;
	}
	cout << '1' << endl;

	return 0;
}