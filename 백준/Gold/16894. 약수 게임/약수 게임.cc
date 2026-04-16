#include <iostream>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using ll = long long;

bool isprime(ll n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int i = 3;
	while (i * i <= n) {
		if (n % i == 0) return false;
		i += 2;
	}
	return true;
}

int divs(ll n) {
	if (n == 1) return 0;
	ll i = 2;
	int cnt = 0;
	while (i * i <= n) {
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		while (!isprime(++i));
	}
	return cnt + (n != 1);
}

int main() {
	FASTIO;

	ll n; cin >> n;
	if (divs(n) == 2) cout << "cubelover\n";
	else cout << "koosaga\n";

	return 0;
}