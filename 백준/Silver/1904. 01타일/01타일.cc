#include <iostream>
#include <vector>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

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

	constexpr int mod = 15746;
	int a = 1, b = 1;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int t = a;
		a = b;
		b = (t + b) % mod;
	}

	cout << a << endl;

	return 0;
}