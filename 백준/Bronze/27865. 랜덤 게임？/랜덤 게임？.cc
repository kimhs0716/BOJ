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
	while (true) {
		cout << "? " << n << endl;
		cout.flush();
		cin.ignore();
		char ch; cin >> ch;
		if (ch == 'Y') {
			cout << "! " << n << endl;
			break;
		}
	}

	return 0;
}