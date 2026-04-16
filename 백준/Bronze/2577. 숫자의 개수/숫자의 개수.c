#include <stdio.h>
int main(){
    int a, b, c, num, arr[10] = {0, };
    scanf("%d %d %d", &a, &b, &c);
    num = a * b * c;
    while(num != 0){
        arr[num % 10]++;
        num /= 10;
    }
    for(int i = 0; i < 10; i++) printf("%d\n", arr[i]);
    return 0;
}
