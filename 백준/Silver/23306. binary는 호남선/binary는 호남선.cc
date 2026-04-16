#include <iostream>
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
int main() {
	int n; cin >> n;
	cout << "? 1" << endl;
	cout.flush();
	int a, b; cin >> a;
	cout << "? " << n << endl;
	cout.flush();
	cin >> b;

	if (b < a) cout << "! -1\n";
	else if (a < b) cout << "! 1\n";
	else cout << "! 0\n";

	return 0;
}