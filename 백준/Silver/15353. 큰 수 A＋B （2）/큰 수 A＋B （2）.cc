#include <iostream>
#include <string>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

constexpr int SIZE = 1 << 16;

typedef struct BigInt {
	bool sign; // +: true, -: false
	string arr;

	BigInt(string s = "0") {
		arr = string(SIZE, '0');
		int idx = 0;
		sign = true;
		if (s[0] == '-') sign = false, idx++;
		for (int i = s.length() - 1; i >= idx; i--) {
			arr[s.length() - i - 1] = s[i];
		}
	}

	BigInt(long long int n) {
		string s = to_string(n);
		arr = string(SIZE, '0');
		int idx = 0;
		sign = true;
		if (s[0] == '-') sign = false, idx++;
		for (int i = s.length() - 1; i >= idx; i--) {
			arr[s.length() - i - 1] = s[i];
		}
	}

	void debug() {
		cout << "===== #[DEBUG] =====\n";
		if (sign == false) cout << '-';
		for (int i = SIZE - 1; i >= 0; i--) cout << arr[i];
		cout << endl;
	}

	BigInt operator+(const BigInt& b) {
		BigInt result;
		if (sign == b.sign) {
			result.sign = sign;
			for (int i = 0; i < SIZE; i++) {
				result.arr[i] += arr[i] + b.arr[i] - ('0' << 1);
				if (result.arr[i] > '9') {
					result.arr[i] -= 10;
					if (i + 1 < SIZE) result.arr[i + 1]++;
				}
			}
		}
		else { // if (sign != b.sign)
			if ((*this) < b) result.sign = b.sign; // abs(this) < abs(b)
			else result.sign = sign;
			for (int i = 0; i < SIZE; i++) {
				result.arr[i] += b.arr[i] - arr[i];
				if (result.arr[i] < '0') {
					result.arr[i] += 10;
					if (i + 1 < SIZE) result.arr[i + 1]--;
				}
			}
		}
		return result;
	}

	bool operator<(const BigInt& b) {
		int idx = SIZE - 1;
		while (idx >= 0) {
			if (arr[idx] < b.arr[idx]) return true;
			if (arr[idx] > b.arr[idx]) return false;
			idx--;
		}
		return false;
	}

} BigInt;

ostream& operator<<(ostream& os, const BigInt& b) {
	if (b.sign == false) cout << '-';
	int idx = SIZE - 1; while (idx && b.arr[idx] == '0') idx--; idx++;
	while (idx--) cout << b.arr[idx];
	return os;
}

istream& operator>>(istream& is, BigInt& b) {
	string t; is >> t;
	b = BigInt(t);
	return is;
}

int main() {
	FASTIO;

	BigInt a, b; cin >> a >> b;
	cout << a + b << endl;

	return 0;
}
