#include <stdio.h>
int main(){
    int num, arr[42] = {0, }, count = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        arr[num % 42]++;
    }
    for(int i = 0; i < 42; i++) if(arr[i] != 0) count++;
    printf("%d", count);
    return 0;
}
