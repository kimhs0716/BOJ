#include <stdio.h>
int main() {
    long long int s, sum = 0;
    scanf("%lld", &s);
    int i = 1;
    while(sum <= s){
        sum += i;
        i++;
    }
    printf("%d", i - 2);
    return 0;
}
