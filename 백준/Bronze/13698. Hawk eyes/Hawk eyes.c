#include <stdio.h>
#include <string.h>
int main(){
    char str[201];
    scanf("%s", str);
    int n = strlen(str);
    int big = 4, small = 1;
    for(int i = 0; i < n; i++){
        if(str[i] == 'A'){
            if(small == 1) small = 2;
            else if(small == 2) small = 1;
            if(big == 1) big = 2;
            else if(big == 2) big = 1;
        }
        if(str[i] == 'B'){
            if(small == 1) small = 3;
            else if(small == 3) small = 1;
            if(big == 1) big = 3;
            else if(big == 3) big = 1;
        }
        if(str[i] == 'C'){
            if(small == 1) small = 4;
            else if(small == 4) small = 1;
            if(big == 1) big = 4;
            else if(big == 4) big = 1;
        }
        if(str[i] == 'D'){
            if(small == 3) small = 2;
            else if(small == 2) small = 3;
            if(big == 3) big = 2;
            else if(big == 2) big = 3;
        }
        if(str[i] == 'E'){
            if(small == 4) small = 2;
            else if(small == 2) small = 4;
            if(big == 4) big = 2;
            else if(big == 2) big = 4;
        }
        if(str[i] == 'F'){
            if(small == 3) small = 4;
            else if(small == 4) small = 3;
            if(big == 3) big = 4;
            else if(big == 4) big = 3;
        }
    }
    printf("%d\n%d", small, big);
    return 0;
}
