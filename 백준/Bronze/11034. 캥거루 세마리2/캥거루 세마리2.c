#include <stdio.h>
int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        int count = 0;
        while(a + 1 != b || b + 1 != c){
            count++;
            if(c - b > b - a){
                a = b;
                b = c - 1;
            }
            else{
                c = b;
                b = a + 1;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
