#include <stdio.h>
int main(){
    int num, temp, count = 1;
    scanf("%d", &num);
    temp = num % 10 * 10 + (num / 10 + num) % 10;
    while(temp != num){
        count++;
        temp = temp % 10 * 10 + (temp / 10 + temp) % 10;
    }
    printf("%d", count);
    return 0;
}
