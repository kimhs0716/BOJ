#include <stdio.h>
int main(){
    int t, a, s;
    char c;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        s = 0;
        while(1){
            scanf("%d%c", &a, &c);
            s += a;
            if(c == 10) break;
        }
        printf("%d\n", s);
    }
    return 0;
}
