#include <stdio.h>
int main(){
    int a[4];
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    printf("%d", a[0] * a[2]);
    return 0;
}
