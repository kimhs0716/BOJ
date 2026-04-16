#include <stdio.h>
#include <string.h>
#include <math.h>
int bin2dec(char* a, int size){
    int res = 0;
    for(int i = size - 1; i >= 0; i--)
        res += (int)pow(2.0, size - i - 1) * (a[i] - '0');
    return res;
}
void dec2bin(long long int a){
    if(a){
        dec2bin(a / 2);
        printf("%lld", a % 2);
    }
}
int main(){
    char a[31], b[31];
    long long int n1, n2;
    scanf("%s %s", a, b);
    n1 = bin2dec(a, strlen(a));
    n2 = bin2dec(b, strlen(b));
    dec2bin(n1 * n2);
    return 0;
}
