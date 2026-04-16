#include <iostream>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
	FASTIO;

	double k, a, b, c, d; cin >> k >> a >> b >> c >> d;
	long long int fk1 = a * k + b, fk2 = c * k + d;
	if (fk1 == fk2) {
		cout << "Yes " << fk1 << endl;
	}
	else cout << "No\n";

	return 0;
}
