#include <iostream>
#include <vector>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define MOD 1000

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
Matrix S(Matrix& m, ll n);
istream& operator>>(istream& is, Matrix& m);
ostream& operator<<(ostream& os, const Matrix& m);

int main() {
	FASTIO;

	int n; ll b;
	cin >> n >> b;
	Matrix mat(n, n);
	cin >> mat;
	cout << S(mat, b) << endl;

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

Matrix S(Matrix& m, ll n) {
	if (n == 0) return Matrix(m.r, m.c);
	if (n & 1) return S(m, n - 1) + (m ^ n);
	return S(m, n >> 1) * (I(m.r) + (m ^ (n >> 1)));
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