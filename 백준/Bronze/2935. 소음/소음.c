#include <stdio.h>
#include <string.h>
int main() {
    char a[101], b, c[101];
    scanf("%s %c %s", a, &b, c);
    if(b == '+'){
        int n = strlen(a), m = strlen(c);
        if(n == m){
            printf("2");
            for(int i = 0; i < n - 1; i++) printf("0");
        }
        else{
            for(int i = (n < m) ? m : n; i > 0; i--){
                if(i == n || i == m) printf("1");
                else printf("0");
            }
        }
    }
    else{
        int n = strlen(a), m = strlen(c);
        printf("1");
        for(int i = 0; i < n + m - 2; i++) printf("0");
    }
    return 0;
}
