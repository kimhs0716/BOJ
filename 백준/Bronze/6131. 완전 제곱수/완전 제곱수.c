#include <stdio.h>
int main(){
    int a, b, n, c = 0;
    scanf("%d", &n);
    for(a = 1; a <= 500; a++)
        for(b = 1; b <= 500; b++)
            if(a * a == b * b + n) c++;
    printf("%d", c);
    return 0;
}
