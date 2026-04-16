#include <stdio.h>
int main(){
    char aah[101];
    int c = 1;
    scanf("%s", aah);
    int i = 0;
    while(aah[i]){
        if(aah[i] == ',') c++;
        i++;
    }
    printf("%d", c);
}
