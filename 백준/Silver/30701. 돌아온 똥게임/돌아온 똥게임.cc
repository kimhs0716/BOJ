#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main() {
	FASTIO;
	
	int n, d; cin >> n >> d;
	vi monster, equipment;
	int cnt = 0;

	while (n--) {
		int a, x; cin >> a >> x;
		if (a == 1) {
			monster.push_back(x);
		}
		else {
			equipment.push_back(x);
		}
	}

	sort(monster.rbegin(), monster.rend());
	sort(equipment.rbegin(), equipment.rend());

	while (true) {
		if (!monster.empty() && monster.back() < d) {
			if (1 <= d && d <= 1e9) d += monster.back();
			if (d < 1 || d > 1e9) d = 1e9 + 1;
			monster.pop_back();
		}
		else if (!equipment.empty()) {
			if (1 <= d && d <= 1e9) d *= equipment.back();
			if (d < 1 || d > 1e9) d = 1e9 + 1;
			equipment.pop_back();
		}
		else {
			break;
		}
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}