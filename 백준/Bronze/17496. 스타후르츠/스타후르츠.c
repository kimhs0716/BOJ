#include <stdio.h>
int main(){
    int n, t, c, p, crop = 0, sum = 0;
    scanf("%d %d %d %d", &n, &t, &c, &p);
    for(int i = 1; i < n; i++){
        crop++;
        if(crop == t){
            crop = 0;
            sum++;
        }
    }
    printf("%d\n", c * sum * p);
    return 0;
}
