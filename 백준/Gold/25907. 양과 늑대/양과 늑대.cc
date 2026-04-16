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
	int m = 0, M = n;
	while (true) {
		int mid = (m + M) / 2;
		cout << "? " << mid << endl;
		cout.flush();
		int sheep, wolf; cin >> sheep;
		wolf = mid - sheep;
		if (sheep == wolf) {
			cout << "! " << mid << endl;
			break;
		}
		if (sheep > wolf) m = mid;
		else M = mid;
	}

	return 0;
}