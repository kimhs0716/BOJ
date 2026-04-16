#include <stdio.h>
#define M 1234567891
#define r 31
int main(){
    int n;
    scanf("%d", &n);
    char chr;
    long long int s = 0;
    long long int tr = 1;
    for(int i = 0; i < n; i++){
        scanf(" %c", &chr);
        chr = chr - 'a' + 1;
        //printf("%d %d %d\n", chr, s, tr);
        s += (tr * chr) % M;
        tr = (tr * r) % M;
        s %= M;
    }
    printf("%d", s % M);
    return 0;
}
