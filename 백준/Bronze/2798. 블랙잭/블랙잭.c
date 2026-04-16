#include <stdio.h>
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[100] = {0, };
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int M = 0;
	for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                int s = arr[i] + arr[j] + arr[k];
                if(s <= m && s > M) M = s;
            }
        }
	}
	printf("%d\n", M);
	return 0;
}
