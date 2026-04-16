#include <stdio.h>
int main() {
    int n, a = 0;
    scanf("%d", &n);
    char str[20];
    scanf("%s", str);
    int i = -1;
    while(str[++i]){
        if(str[i] == 'A') a++;
        else a--;
    }
    printf((a < 0) ? "B" : ((a > 0) ? "A" : "Tie"));
    return 0;
}
