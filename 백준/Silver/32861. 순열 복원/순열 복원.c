#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[1005];
	char check[3005] = { 0, };

	int n;
	scanf("%d", &n);
	char flag = 1;

	for (int i = 0; i < n; i++) {
		int s = 0, m;
		for (int j = 0; j < n; j++) {
			scanf("%d", &m);
			if (i == j && m != 0) flag = 0;
			if (m == 0 && i != j) flag = 0;
			s += m;
		}
		s = n - s;
		if (s % 2 == 0) flag = 0;
		s = (s + 1) >> 1;
		arr[i] = s;
		check[s] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			flag = 0;
			break;
		}
	}

	if (flag) {
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
	}
	else {
		printf("-1");
	}

	return 0;
}
