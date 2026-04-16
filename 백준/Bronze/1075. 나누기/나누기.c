#include <stdio.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    a = (a / 100) * 100;
    for(int i = 0; i < 100; i++){
        if((a + i) % b == 0){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
