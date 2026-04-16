#include <iostream>
#include <vector>
#include <set>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;

int main() {
	FASTIO;

	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		int n; ll d; cin >> n >> d;
		vl arr(n); for (int j = 0; j < n; j++) cin >> arr[j];
		ll cur = d;
		for (int j = n - 1; j >= 0; j--) {
			cur = cur / arr[j] * arr[j];
		}
		cout << "Case #" << i << ": " << cur << endl;
	}

	return 0;
}