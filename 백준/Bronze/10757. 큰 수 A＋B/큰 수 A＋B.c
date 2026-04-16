#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char n1[10001] = {0, }, n2[10001] = {0, };
    int carry = 0;
    int l1, l2;
    int i = 0;
    int isfirst = 1;
    scanf("%s %s", n1, n2);
    l1 = strlen(n1);
    l2 = strlen(n2);
    for(int i = l1 - 1; i >= 0; i--) { n1[10000 - l1 + 1 + i] = n1[i] - '0'; n1[i] = 0; }
    for(int i = l2 - 1; i >= 0; i--) { n2[10000 - l2 + 1 + i] = n2[i] - '0'; n2[i] = 0; }
    for(int i = 10000; i > 0; i--){
        n1[i] += n2[i];
        if(n1[i] >= 10){
            n1[i] -= 10;
            n1[i - 1]++;
        }
    }
    for(int i = 0; i < 10001; i++){
        if(n1[i] == 0 && isfirst) continue;
        isfirst = 0;
        printf("%d", n1[i]);
    }
    return 0;
}
