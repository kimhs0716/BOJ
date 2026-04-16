#include <stdio.h>
int main(){
    int num, count = 0;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++) count += ishan(i);
    printf("%d", count);
    return 0;
}

int ishan(int n){
    if(n == 1000) return 0;
    if(n < 100) return 1;
    int arr[3] = {0, };
    int i = 0;
    while(n != 0) {
        arr[i] = n % 10;
        i++;
        n /= 10;
    }
    if(arr[0] + arr[2] == 2 * arr[1]) return 1;
    return 0;
}
