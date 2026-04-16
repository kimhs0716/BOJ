#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	if (m <= 26) {
		printf("SN %d%c\n", n, 'A' + m - 1);
	}
	else {
		int q = m / 26;
		int r = m % 26;
		if (r == 0) {
			q--;
			r = 26;
		}
		printf("SN %d%c%c\n", n, 'a' + q - 1, 'a' + r - 1);
	}
	return 0;
}