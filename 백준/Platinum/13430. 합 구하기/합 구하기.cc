#include <iostream>
#include <cstring>
#define mod 1000000007
using namespace std;
typedef long long int lld;
class Matrix {
public:
	size_t row, col;
	lld** mat;
	size_t ms;
	Matrix(int r, int c);
	Matrix(const Matrix& m1);
	~Matrix();
	Matrix operator*(Matrix m1);
	void operator=(Matrix m1);
	void input();
	void print();
};

Matrix __pow(Matrix m1, int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;
	Matrix A(k + 2, k + 2);
	for (int i = 0; i < k + 2; i++) {
		for (int j = 0; j <= i; j++) {
			A.mat[i][j] = 1;
		}
	}

	Matrix S0(k + 2, 1);
	for (int i = 0; i < k + 2; i++) {
		S0.mat[i][0] = 1;
	}

	A = __pow(A, n - 1);

	Matrix Sn = A * S0;

	cout << Sn.mat[k + 1][0] << endl;

	/*
	A.print();
	for(int i = 0; i < 50; i++) cout << "=";
	cout << endl;
	Sn.print();
	*/

	return 0;
}

Matrix::Matrix(int r, int c) {
	row = r;
	col = c;
	ms = sizeof(lld) * col;
	mat = new lld * [row];
	for (int i = 0; i < row; i++) {
		mat[i] = new lld[col];
		memset(mat[i], 0, ms);
	}
}

Matrix::Matrix(const Matrix& m1) {
	row = m1.row;
	col = m1.col;
	ms = m1.ms;
	mat = new lld * [row];
	for (int i = 0; i < row; i++) {
		mat[i] = new lld[col];
		memcpy(mat[i], m1.mat[i], ms);
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

Matrix Matrix::operator*(Matrix m1) {
	Matrix result(row, m1.col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < m1.col; j++) {
			lld s = 0;
			for (int k = 0; k < col; k++) {
				s += (mat[i][k] * m1.mat[k][j]) % mod;
				s %= mod;
			}
			result.mat[i][j] = s;
		}
	}
	return result;
}

void Matrix::operator=(Matrix m1) {
	row = m1.row;
	col = m1.col;
	ms = m1.ms;
	mat = new lld * [row];
	for (int i = 0; i < row; i++) {
		mat[i] = new lld[col];
		memcpy(mat[i], m1.mat[i], ms);
	}
}

void Matrix::input() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> mat[i][j];
		}
	}
}

void Matrix::print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}

Matrix __pow(Matrix m1, int n) {
	if (n == 0) {
		Matrix I(m1.row, m1.col);
		for (int i = 0; i < I.row; i++)
			I.mat[i][i] = 1;
		return I;
	}
	Matrix res = __pow(m1, n / 2);
	res = res * res;
	if (n & 1) res = res * m1;
	return res;
}
