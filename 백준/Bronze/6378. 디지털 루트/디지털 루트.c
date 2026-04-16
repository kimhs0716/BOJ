#include <stdio.h>
#include <string.h>
int main() {
    int a;
    char in[1001];
    while(1){
        scanf("%s", in);
        if(in[0] == '0') break;
        a = 0;
        for(int i = 0; i < strlen(in); i++){
            a += in[i] - '0';
        }
        int s;
        while(1){
            s = 0;
            while(a){
                s += a % 10;
                a /= 10;
            }
            if(s < 10) break;
            a = s;
        }
        printf("%d\n", s);
    }
    return 0;
}
