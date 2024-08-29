#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define inf 1987654321
using namespace std;
class debugstream {
public:
	ostream& os;
	debugstream(ostream& os) :os(os) {}
	template <typename T>
	ostream& operator<<(const T& obj) {
		return os << "#[DEBUG]: " << obj;
	}
};
debugstream dout(cout);
typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
int main() {
	FASTIO;

	constexpr int size = 1e6;
	bool* isprime = new bool[size + 1];
	for (int i = 1; i <= size; i++) *(isprime + i) = true;
	isprime[0] = isprime[1] = false;
	int i = 2;
	while (i <= size) {
		int j = 2;
		while (i * j <= size) {
			isprime[i * j++] = false;
		}
		i++;
		while (i <= size && isprime[i] == false) i++;
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 0;
		for (int i = 2; i < n / 2 + 1; i++) {
			if (!isprime[i]) continue;
			if (isprime[n - i]) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}