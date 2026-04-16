#include <stdio.h>
int main() {
    int a, min = 100, sum = 0;
    for(int i = 0; i < 4; i++){
        scanf("%d", &a);
        min = (min > a) ? a : min;
        sum += a;
    }
    sum -= min;
    min = 100;
    for(int i = 0; i < 2; i++){
        scanf("%d", &a);
        min = (min > a) ? a : min;
        sum += a;
    }
    sum -= min;
    printf("%d", sum);
    return 0;
}
