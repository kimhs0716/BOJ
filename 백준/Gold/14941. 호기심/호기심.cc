#include <iostream>
#include <vector>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using vi = vector<int>;

int main() {
	FASTIO;

	vector<bool> arr(100001, 1);
	arr[0] = arr[1] = 0;
	int i = 2;
	while (i * i <= 100000) {
		int j = 2;
		while (i * j <= 100000) arr[i * j++] = 0;
		while (!arr[++i]);
	}

	vi primes;
	for (int i = 0; i <= 100000; i++) {
		if (arr[i]) primes.push_back(i);
	}

	// cout << primes.size() << endl;

	int tc; cin >> tc;

	while (tc--) {
		int ans = 0;
		int a, b; cin >> a >> b;
		bool flag = true;
		int idx = -1;
		while (primes[++idx] < a);
		while (idx < primes.size() && primes[idx] <= b) {
			// cout << primes[idx] << ' ';
			if (flag) ans += 3 * primes[idx];
			else ans -= primes[idx];
			idx++;
			flag ^= 1;
		}
		cout << ans << endl;
	}

	return 0;
}