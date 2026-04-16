#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

bool isprime(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	int i = 3;
	while (i * i <= n) {
		if (n % i == 0) return 0;
		i += 2;
	}
	return 1;
}

int main() {
	int n, k; cin >> n >> k;
	vector<int> primes;
	for (int i = 2; i <= k; i++) {
		if (isprime(i)) primes.push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int t = i;
		for (int p : primes) {
			if (p > t) break;
			while (t % p == 0) t /= p;
		}
		if (t == 1) ans++;
	}
	cout << ans << endl;

	return 0;
}