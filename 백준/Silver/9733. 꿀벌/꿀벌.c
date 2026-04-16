#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int arr[7] = { 0, }, sum = 0;
	char str[3], s[7][3] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };
	while (scanf("%s", str) != EOF) {
		for (int i = 0; i < 7; i++) {
			if (strcmp(str, s[i]) == 0) {
				arr[i]++;
				break;
			}
		}
		sum++;
	}

	for (int i = 0; i < 7; i++) {
		printf("%s %d %.2f\n", s[i], arr[i], (double)arr[i] / sum);
	}
	printf("Total %d 1.00\n", sum);

	return 0;
}