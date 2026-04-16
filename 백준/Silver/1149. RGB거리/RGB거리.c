#include <stdio.h>
int min(int a, int b){
    return (a < b) ? a : b;
}
int main(){
    int n;
    scanf("%d", &n);
    int price[n][3];
    for(int i = 0; i < n; i++){
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        if(i == 0){
            price[i][0] = r;
            price[i][1] = g;
            price[i][2] = b;
        }
        else{
            price[i][0] = min(price[i - 1][1], price[i - 1][2]) + r;
            price[i][1] = min(price[i - 1][0], price[i - 1][2]) + g;
            price[i][2] = min(price[i - 1][0], price[i - 1][1]) + b;
        }
    }
    printf("%d", min(min(price[n - 1][0], price[n - 1][1]), price[n - 1][2]));
    return 0;
}
