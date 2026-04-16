#include <stdio.h>
int main() {
    int n;
    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        int s = 0;
        int arr[100] = {0, };
        int i = 0;
        for(int a = 1; a < n; a++){
            if(n % a == 0){
                s += a;
                arr[i++] = a;
            }
        }
        if(s == n){
            printf("%d = ", n);
            for(int j = 0; j < i - 1; j++)
                printf("%d + ", arr[j]);
            printf("%d\n", arr[i - 1]);
        }
        else printf("%d is NOT perfect.\n", n);
    }
    return 0;
}
