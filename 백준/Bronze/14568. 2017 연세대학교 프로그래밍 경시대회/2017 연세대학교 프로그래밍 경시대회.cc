#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int s = 0;
    for(int i = 2; i < n - 1; i += 2)
        s += (n - i - 2) / 2;
    printf("%d", s);
    return 0;
}
