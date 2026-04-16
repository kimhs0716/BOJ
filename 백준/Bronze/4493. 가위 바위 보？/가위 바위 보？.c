#include <stdio.h>
int main(){
    int a, b;
    char c, d;
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        int e = 0, f = 0;
        scanf("%d", &b);
        for(int j = 0; j < b; j++){
            scanf(" %c %c", &c, &d);
            if(c == d) continue;
            if(c == 'R'){
                if(d == 'P') f++;
                else e++;
            }
            if(c == 'S'){
                if(d == 'R') f++;
                else e++;
            }
            if(c == 'P'){
                if(d == 'S') f++;
                else e++;
            }
        }
        if(e == f) printf("TIE\n");
        else if (e > f) printf("Player 1\n");
        else printf("Player 2\n");
    }
}
