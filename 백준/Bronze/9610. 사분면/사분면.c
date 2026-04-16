#include <stdio.h>
int main() {
    int t, a, b, q[5] = {0, };
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        if(a * b == 0) q[4]++;
        else if(a > 0){
            if(b > 0) q[0]++;
            else q[3]++;
        }
        else{
            if(b < 0) q[2]++;
            else q[1]++;
        }
    }
    for(int i = 0; i < 4; i++){
        printf("Q%d: %d\n", i + 1, q[i]);
    }
    printf("AXIS: %d", q[4]);
    return 0;
}
