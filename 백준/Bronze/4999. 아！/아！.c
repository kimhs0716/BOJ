#include <stdio.h>
#include <string.h>
int main(){
    char aah[1001];
    int l;
    scanf("%s", aah);
    l = strlen(aah);
    scanf("%s", aah);
    printf((l >= strlen(aah)) ? "go" : "no");
}
