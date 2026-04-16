#include <stdio.h>
int main(){
    int a, b, c;
    a = b = 2000;
    for(int i = 0; i < 3; i++){
        scanf("%d", &c);
        a = (c < a) ? c : a;
    }
    for(int i = 0; i < 2; i++){
        scanf("%d", &c);
        b = (c < b) ? c : b;
    }
    printf("%d\n", a + b - 50);
    return 0;
}
