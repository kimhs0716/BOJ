#include <stdio.h>
int bunhae(int n){
    int res = n;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main() {
    int n, found = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
        if(bunhae(i) == n){
            printf("%d", i);
            found = 1;
            break;
        }
    if(found == 0) printf("0");
	return 0;
}
