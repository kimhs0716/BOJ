#include <stdio.h>
int f(int n){
    return 3 * n * n - 9 * n + 8;
}
int main(){
    int n;
    scanf("%d", &n);
    if(n == 1) printf("1");
    else if(n == 2) printf("2");
    else{
        int i = 2;
        while(f(i) <= n) i++;
        printf("%d", i - 1);
    }
    return 0;
}
