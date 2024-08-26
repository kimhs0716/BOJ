#include <iostream>
#include <vector>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using vi = vector<int>;

int n, m, c1, c2, ans;
vi arr1, arr2;

int main() {
	FASTIO;

	while (true) {
		ans = c1 = c2 = 0;
		cin >> n;
		if (n == 0) break;
		arr1 = vi(n);
		while (n--) cin >> arr1[n];
		cin >> m;
		arr2 = vi(m);
		while (m--) cin >> arr2[m];

		while (true) {
			if (arr1.empty() || arr2.empty()) {
				int s1 = 0, s2 = 0;
				for (int i : arr1) s1 += i;
				for (int i : arr2) s2 += i;
				ans += max<int>(c1 + s1, c2 + s2);
				break;
			}
			if (arr1.back() < arr2.back()) {
				c1 += arr1.back();
				arr1.pop_back();
			}
			else if (arr1.back() > arr2.back()) {
				c2 += arr2.back();
				arr2.pop_back();
			}
			else {
				ans += max<int>(c1, c2) + arr1.back();
				arr1.pop_back();
				arr2.pop_back();
				c1 = c2 = 0;
			}
		}

		cout << ans << endl;
	}


	return 0;
}
