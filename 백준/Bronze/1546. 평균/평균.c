#include <stdio.h>
int main(){
    int num, sum = 0, s, max = -1;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &s);
        max = (max < s) ? s : max;
        sum += s;
    }
    printf("%f", (double)sum / num / max * 100);
    return 0;
}
