#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
constexpr int mod = 1e9 + 7;
void __copy(char dst[][3], const char src[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
class Cube {
public:
	char temp[3][3];
	char front[3][3], up[3][3], down[3][3];
	char left[3][3], right[3][3], back[3][3];
	Cube() {
		for(int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				up[i][j] = 'w';
				front[i][j] = 'r';
				left[i][j] = 'g';
				down[i][j] = 'y';
				right[i][j] = 'b';
				back[i][j] = 'o';
			}
	}
	Cube &print() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << up[i][j];
			}
			cout << endl;
		}
		return *this;
	}
	Cube& debug() {
		cout << "=====#[DEBUG]=====\n";

		cout << "    " << up[0][0] << up[0][1] << up[0][2] << endl;
		cout << "    " << up[1][0] << up[1][1] << up[1][2] << endl;
		cout << "    " << up[2][0] << up[2][1] << up[2][2] << endl;

		for (int i = 0; i < 3; i++) {
			cout << left[i][0] << left[i][1] << left[i][2] << ' ';
			cout << front[i][0] << front[i][1] << front[i][2] << ' ';
			cout << right[i][0] << right[i][1] << right[i][2] << ' ';
			cout << back[i][0] << back[i][1] << back[i][2] << endl;
		}

		cout << "    " << down[0][0] << down[0][1] << down[0][2] << endl;
		cout << "    " << down[1][0] << down[1][1] << down[1][2] << endl;
		cout << "    " << down[2][0] << down[2][1] << down[2][2] << endl;
		return *this;
	}
	Cube& U() {
		__copy(temp, up);
		up[0][0] = temp[2][0], up[0][1] = temp[1][0], up[0][2] = temp[0][0];
		up[1][0] = temp[2][1], up[1][1] = temp[1][1], up[1][2] = temp[0][1];
		up[2][0] = temp[2][2], up[2][1] = temp[1][2], up[2][2] = temp[0][2];
		__copy(temp, left);
		left[0][0] = front[0][0], left[0][1] = front[0][1], left[0][2] = front[0][2];
		front[0][0] = right[0][0], front[0][1] = right[0][1], front[0][2] = right[0][2];
		right[0][0] = back[0][0], right[0][1] = back[0][1], right[0][2] = back[0][2];
		back[0][0] = temp[0][0], back[0][1] = temp[0][1], back[0][2] = temp[0][2];

		return *this;
	}
	Cube& F() {
		__copy(temp, front);
		front[0][0] = temp[2][0], front[0][1] = temp[1][0], front[0][2] = temp[0][0];
		front[1][0] = temp[2][1], front[1][1] = temp[1][1], front[1][2] = temp[0][1];
		front[2][0] = temp[2][2], front[2][1] = temp[1][2], front[2][2] = temp[0][2];
		__copy(temp, left);
		left[0][2] = down[0][0], left[1][2] = down[0][1], left[2][2] = down[0][2];
		down[0][0] = right[2][0], down[0][1] = right[1][0], down[0][2] = right[0][0];
		right[0][0] = up[2][0], right[1][0] = up[2][1], right[2][0] = up[2][2];
		up[2][0] = temp[2][2], up[2][1] = temp[1][2], up[2][2] = temp[0][2];
		return *this;
	}
	Cube& R() {
		__copy(temp, right);
		right[0][0] = temp[2][0], right[0][1] = temp[1][0], right[0][2] = temp[0][0];
		right[1][0] = temp[2][1], right[1][1] = temp[1][1], right[1][2] = temp[0][1];
		right[2][0] = temp[2][2], right[2][1] = temp[1][2], right[2][2] = temp[0][2];
		__copy(temp, up);
		up[0][2] = front[0][2], up[1][2] = front[1][2], up[2][2] = front[2][2];
		front[0][2] = down[0][2], front[1][2] = down[1][2], front[2][2] = down[2][2];
		down[0][2] = back[2][0], down[1][2] = back[1][0], down[2][2] = back[0][0];
		back[0][0] = temp[2][2], back[1][0] = temp[1][2], back[2][0] = temp[0][2];
		return *this;
	}
	Cube& L() {
		__copy(temp, left);
		left[0][0] = temp[2][0], left[0][1] = temp[1][0], left[0][2] = temp[0][0];
		left[1][0] = temp[2][1], left[1][1] = temp[1][1], left[1][2] = temp[0][1];
		left[2][0] = temp[2][2], left[2][1] = temp[1][2], left[2][2] = temp[0][2];
		__copy(temp, up);
		up[0][0] = back[2][2], up[1][0] = back[1][2], up[2][0] = back[0][2];
		back[0][2] = down[2][0], back[1][2] = down[1][0], back[2][2] = down[0][0];
		down[0][0] = front[0][0], down[1][0] = front[1][0], down[2][0] = front[2][0];
		front[0][0] = temp[0][0], front[1][0] = temp[1][0], front[2][0] = temp[2][0];
		return *this;
	}
	Cube& D() {
		__copy(temp, down);
		down[0][0] = temp[2][0], down[0][1] = temp[1][0], down[0][2] = temp[0][0];
		down[1][0] = temp[2][1], down[1][1] = temp[1][1], down[1][2] = temp[0][1];
		down[2][0] = temp[2][2], down[2][1] = temp[1][2], down[2][2] = temp[0][2];
		__copy(temp, front);
		front[2][0] = left[2][0], front[2][1] = left[2][1], front[2][2] = left[2][2];
		left[2][0] = back[2][0], left[2][1] = back[2][1], left[2][2] = back[2][2];
		back[2][0] = right[2][0], back[2][1] = right[2][1], back[2][2] = right[2][2];
		right[2][0] = temp[2][0], right[2][1] = temp[2][1], right[2][2] = temp[2][2];
		return *this;
	}
	Cube& B() {
		__copy(temp, back);
		back[0][0] = temp[2][0], back[0][1] = temp[1][0], back[0][2] = temp[0][0];
		back[1][0] = temp[2][1], back[1][1] = temp[1][1], back[1][2] = temp[0][1];
		back[2][0] = temp[2][2], back[2][1] = temp[1][2], back[2][2] = temp[0][2];
		__copy(temp, up);
		up[0][0] = right[0][2], up[0][1] = right[1][2], up[0][2] = right[2][2];
		right[0][2] = down[2][2], right[1][2] = down[2][1], right[2][2] = down[2][0];
		down[2][0] = left[0][0], down[2][1] = left[1][0], down[2][2] = left[2][0];
		left[0][0] = temp[0][2], left[1][0] = temp[0][1], left[2][0] = temp[0][0];
		return *this;
	}
	Cube& U_prime() {
		return U().U().U();
	}
	Cube& R_prime() {
		return R().R().R();
	}
	Cube& D_prime() {
		return D().D().D();
	}
	Cube& L_prime() {
		return L().L().L();
	}
	Cube& B_prime() {
		return B().B().B();
	}
	Cube& F_prime() {
		return F().F().F();
	}
};
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		Cube c;
		for (int i = 0; i < n; i++) {
			string cmd; cin >> cmd;
			if (cmd == "U+") c.U();
			else if (cmd == "U-") c.U_prime();
			else if (cmd == "F+") c.F();
			else if (cmd == "F-") c.F_prime();
			else if (cmd == "L+") c.L();
			else if (cmd == "L-") c.L_prime();
			else if (cmd == "R+") c.R();
			else if (cmd == "R-") c.R_prime();
			else if (cmd == "B+") c.B();
			else if (cmd == "B-") c.B_prime();
			else if (cmd == "D+") c.D();
			else c.D_prime();
			//c.debug();
		}
		c.print();
	}

	return 0;
}
