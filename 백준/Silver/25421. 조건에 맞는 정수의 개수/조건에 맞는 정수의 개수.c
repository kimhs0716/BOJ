#include <stdio.h>
#define MOD 987654321

int arr[100001][9];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < 9; i++) arr[0][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = -2; k <= 2; k++) {
                if (0 <= j + k && j + k < 9) arr[i][j] += arr[i - 1][j + k];
                arr[i][j] %= MOD;
            }
        }
    }
    
    long long int sum = 0;
    for (int i = 0; i < 9; i++) sum += arr[n - 1][i];
    printf("%d\n", sum % MOD);

    return 0;
}