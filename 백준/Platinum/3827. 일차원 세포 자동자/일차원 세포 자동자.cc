#include <iostream>
#include <vector>
#include <sstream>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int MOD = 1e9;

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;

class Matrix {
public:
	int r, c;
	vvi arr;
	Matrix(int r, int c);
	Matrix operator+(const Matrix& m) const;
	Matrix operator*(const Matrix& m) const;
	Matrix operator^(ll n) const;
};

Matrix I(int n);
istream& operator>>(istream& is, Matrix& m);
ostream& operator<<(ostream& os, const Matrix& m);

int main() {
	FASTIO;

	int n, m, a, b, c, t;
	while (true) {
		cin >> n >> m >> a >> b >> c >> t;
		if (n == 0) break;
		MOD = m;
		Matrix mat(1, n);
		Matrix r(n, n);
		cin >> mat;
		for (int i = 0; i < n - 1; i++) r.arr[i][i + 1] = a;
		for (int i = 0; i < n; i++) r.arr[i][i] = b;
		for (int i = 0; i < n - 1; i++) r.arr[i + 1][i] = c;
		cout << mat * (r ^ t);
	}

	return 0;
}

Matrix::Matrix(int r, int c) {
	this->r = r;
	this->c = c;
	arr = vvi(r, vi(c, 0));
}

Matrix Matrix::operator+(const Matrix& m) const {
	Matrix ret(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ret.arr[i][j] = (arr[i][j] + m.arr[i][j]) % MOD;
		}
	}
	return ret;
}

Matrix Matrix::operator*(const Matrix& m) const {
	Matrix ret(r, m.c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < m.c; j++) {
			int s = 0;
			for (int k = 0; k < c; k++) s = (s + arr[i][k] * m.arr[k][j]) % MOD;
			ret.arr[i][j] = s;
		}
	}
	return ret;
}

Matrix Matrix::operator^(ll n) const {
	if (n == 0) return I(r);
	Matrix ret = *this ^ (n >> 1);
	ret = ret * ret;
	if (n & 1) ret = ret * (*this);
	return ret;
}

Matrix I(int n) {
	Matrix ret(n, n);
	for (int i = 0; i < n; i++) {
		ret.arr[i][i] = 1;
	}
	return ret;
}

istream& operator>>(istream& is, Matrix& m) {
	for (int i = 0; i < m.r; i++) {
		for (int j = 0; j < m.c; j++) {
			is >> m.arr[i][j];
		}
	}
	return is;
}

ostream& operator<<(ostream& os, const Matrix& m) {
	for (int i = 0; i < m.r; i++) {
		for (int j = 0; j < m.c; j++) {
			os << m.arr[i][j] << ' ';
		}
		os << endl;
	}
	return os;
}