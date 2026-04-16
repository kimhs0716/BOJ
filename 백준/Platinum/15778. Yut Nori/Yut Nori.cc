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
void __copy(char dst[][33], const char src[][33]) {
	for (int i = 0; i < 32; i++) strcpy(dst[i], src[i]);
}
class Yutnori {
public:
	char initial_board[32][33];
	char board[32][33];
	int upper[4];
	int lower[4];
	Yutnori() {
		for (int i = 0; i < 4; i++) upper[i] = lower[i] = -1;
		strcpy(initial_board[0], "..----..----..----..----..----..");
		strcpy(initial_board[1], "..    ..    ..    ..    ..    ..");
		strcpy(initial_board[2], "| \\                          / |");
		strcpy(initial_board[3], "|  \\                        /  |");
		strcpy(initial_board[4], "|   \\                      /   |");
		strcpy(initial_board[5], "|    ..                  ..    |");
		strcpy(initial_board[6], "..   ..                  ..   ..");
		strcpy(initial_board[7], "..     \\                /     ..");
		strcpy(initial_board[8], "|       \\              /       |");
		strcpy(initial_board[9], "|        \\            /        |");
		strcpy(initial_board[10], "|         ..        ..         |");
		strcpy(initial_board[11], "|         ..        ..         |");
		strcpy(initial_board[12], "..          \\      /          ..");
		strcpy(initial_board[13], "..           \\    /           ..");
		strcpy(initial_board[14], "|             \\  /             |");
		strcpy(initial_board[15], "|              ..              |");
		strcpy(initial_board[16], "|              ..              |");
		strcpy(initial_board[17], "|             /  \\             |");
		strcpy(initial_board[18], "..           /    \\           ..");
		strcpy(initial_board[19], "..          /      \\          ..");
		strcpy(initial_board[20], "|         ..        ..         |");
		strcpy(initial_board[21], "|         ..        ..         |");
		strcpy(initial_board[22], "|        /            \\        |");
		strcpy(initial_board[23], "|       /              \\       |");
		strcpy(initial_board[24], "..     /                \\     ..");
		strcpy(initial_board[25], "..   ..                  ..   ..");
		strcpy(initial_board[26], "|    ..                  ..    |");
		strcpy(initial_board[27], "|   /                      \\   |");
		strcpy(initial_board[28], "|  /                        \\  |");
		strcpy(initial_board[29], "| /                          \\ |");
		strcpy(initial_board[30], "..    ..    ..    ..    ..    ..");
		strcpy(initial_board[31], "..----..----..----..----..----..");
	}
	pii get_pos(int idx, int ch) {
		pii ret;
		pii ex[] = {
			{5, 25}, {10, 20}, {15, 15}, {20, 10}, {25, 5},
			{5, 5}, {10, 10}, {15, 15}, {20, 20}, {25, 25}
		};
		if (idx <= 4) {
			ret = { 24 - 6 * idx, 30 };
		}
		else if (idx <= 9) {
			ret = { 0, 54 - idx * 6 };
		}
		else if (idx <= 14) {
			ret = { 6 * idx - 54, 0 };
		}
		else if (idx <= 19) {
			ret = { 30, 6 * idx - 84 };
		}
		else ret = ex[idx - 20];
		ret.first += (ch >= 2);
		ret.second += (ch & 1);
		return ret;
	}
	void set_piece(char board[][33], int idx, int ch, bool is_upper) {
		pii pos = get_pos(idx, ch);
		board[pos.first][pos.second] = ch + (is_upper ? 'A' : 'a');
	}
	void print() {
		__copy(board, initial_board);
		for (int i = 0; i < 4; i++) {
			if (upper[i] != -1) {
				set_piece(board, upper[i], i, true);
			}
			if (lower[i] != -1) {
				set_piece(board, lower[i], i, false);
			}
		}
		for (auto i : board) cout << i << endl;
	}
	void debug() {
		print();
		cout << "upper: ";
		for (int i = 0; i < 4; i++) cout << upper[i] << ' ';
		cout << endl;
		cout << "lower: ";
		for (int i = 0; i < 4; i++) cout << lower[i] << ' ';
		cout << endl;
	}
	void go(int ch, string yut, bool is_upper) {
		int score = 0;
		if (yut == "BBBB") score = 5;
		else {
			for (auto i : yut) score += i == 'F';
		}

		int cur;
		if (is_upper) {
			cur = upper[ch];
		}
		else {
			cur = lower[ch];
		}

		int dst;
		if (cur == 4) {
			dst = 19 + score;
		}
		else if (cur == 9) {
			if (score == 3) dst = 22;
			else dst = 24 + score;
		}
		else if (cur == 22) {
			int arr[] = { 22, 28, 29, 19, -1, -1 };
			dst = arr[score];
		}
		else if (20 <= cur && cur <= 24) {
			dst = cur + score;
			if (dst >= 25) dst -= 11;
		}
		else if (25 <= cur && cur <= 29) {
			dst = cur + score;
			if (dst == 27) dst = 22;
			if (dst == 30) dst = 19;
			if (dst >= 31) dst = -1;
		}
		else if (cur == 19) {
			dst = -1;
		}
		else {
			dst = cur + score;
			if (dst == 30) dst = 19;
			if (dst >= 20) dst = -1;
		}

		if (is_upper) {
			upper[ch] = dst;
			for (int i = 0; i < 4; i++) {
				if (lower[i] == dst) lower[i] = -1;
			}
			for (int i = 0; i < 4; i++) {
				if (upper[i] == cur && cur != -1) {
					upper[i] = dst;
				}
			}
		}
		else {
			lower[ch] = dst;
			for (int i = 0; i < 4; i++) {
				if (upper[i] == dst) upper[i] = -1;
			}
			for (int i = 0; i < 4; i++) {
				if (lower[i] == cur && cur != -1) {
					lower[i] = dst;
				}
			}
		}
	}
};
int main() {
	int n; cin >> n;
	Yutnori y;
	while (n--) {
		char ch; string yut;
		cin.ignore();
		cin >> ch >> yut;
		if (isupper(ch)) {
			y.go(ch - 'A', yut, true);
		}
		else {
			y.go(ch - 'a', yut, false);
		}
		//y.debug();
	}
	y.print();

	return 0;
}
