#include <iostream>
#include <vector>
#include <deque>
#include <string>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using vi = vector<int>;

int main() {
	FASTIO;

	char dir = 0;
	int cnt_b = 0, cnt_w = 0;
	string cmd; 
	deque<bool> dq; // 0: ball, 1: wall;
	int q; cin >> q;
	cin.get();
	while (q--) {
		getline(cin, cmd);
		if (cmd == "push b") {
			if (dir % 2 == 1 && dq.empty()) continue;
			dq.push_back(0);
			cnt_b++;
		}
		else if (cmd == "push w") {
			dq.push_back(1);
			cnt_w++;
		}
		else if (cmd == "pop") {
			if (!dq.empty()) {
				if (dq.front() == 1) {
					cnt_w--;
				}
				else {
					cnt_b--;
				}
				dq.pop_front();
			}
		}
		else if (cmd == "rotate l") {
			dir = (dir + 3) % 4;
		}
		else if (cmd == "rotate r") {
			dir = (dir + 1) % 4;
		}
		else if (cmd == "count b") {
			cout << cnt_b << endl;
		}
		else {
			cout << cnt_w << endl;
		}

		if (dir == 3) {
			while (!dq.empty() && dq.back() != 1) dq.pop_back(), cnt_b--;
		}
		else if (dir == 1) {
			while (!dq.empty() && dq.front() != 1) dq.pop_front(), cnt_b--;
		}
	}

	return 0;
}