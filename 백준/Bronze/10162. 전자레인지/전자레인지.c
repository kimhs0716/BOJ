#include <stdio.h>
int main() {
    int t, a, b;
    scanf("%d", &t);
    a = t / 300;
    t %= 300;
    b = t / 60;
    t %= 60;
    if(t % 10 == 0){
        printf("%d %d %d\n", a, b, t / 10);
    }
    else{
        printf("-1\n");
    }
    return 0;
}
