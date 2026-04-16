#include <stdio.h>
int main(){
    int n, res = 0;
    char c[100];
    scanf("%d\n", &n);
    scanf("%s", c);
    for(int i = 0; i < n; i++) res += c[i] - '0';
    printf("%d", res);
    return 0;
}
