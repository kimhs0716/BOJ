#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int d[9];
	int sum = 0;
	int f[9][9];
	int I, J;
	for (int i = 0; i < 9; i++) {
		cin >> d[i];
		sum += d[i];
	}
	sort(d, d + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			f[i][j] = d[i] + d[j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sum - f[i][j] == 100) {
				I = i;
				J = j;
				break;
			}
		}
	}
	for (int k = 0; k < 9; k++) {
		if (k != I && k != J) {
			cout << d[k] << '\n';
		}
	}
	return 0;
}