#include <stdio.h>
int main(){
    int arr[64] = {64, };
    int x;
    scanf("%d", &x);
    int c = 1;
    int sum = 64;
    while(sum != x){
        arr[c - 1] /= 2;
        arr[c] = arr[c - 1];
        c++;
        if(sum - arr[c - 1] >= x){
            c--;
            sum -= arr[c];
            arr[c] = 0;
        }
    }
    printf("%d", c);
    return 0;
}
