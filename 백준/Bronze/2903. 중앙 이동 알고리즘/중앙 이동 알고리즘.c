#include <stdio.h>
int main(){
    int a, res = 1;
    scanf("%d", &a);
    for(int i = 0; i < a; i++)
        res <<= 1;
    res++;
    printf("%d", res * res);
    return 0;
}
