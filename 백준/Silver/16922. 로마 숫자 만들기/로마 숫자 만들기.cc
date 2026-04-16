#include <iostream>
#include <vector>
#include <set>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;
using vi = vector<int>;

int main() {
	FASTIO;

	set<int> s;
	int n; cin >> n;
	for (int I = 0; I <= n; I++) {
		for (int V = 0; V <= n - I; V++) {
			for (int X = 0; X <= n - I - V; X++) {
				int L = n - I - V - X;
				s.insert(I + 5 * V + 10 * X + 50 * L);
			}
		}
	}

	cout << s.size() << endl;

	return 0;
}