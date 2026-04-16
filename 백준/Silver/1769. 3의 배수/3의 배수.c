#include <stdio.h>
int main(){
    char str[1000000];
    scanf("%s", str);
    int count = 1, sum = 0;
    int idx = 0;
    while(str[idx]){
        sum += str[idx] - '0';
        idx++;
    }
    if(sum < 10) count--;
    while(1){
        if(sum < 10) break;
        int tmp = 0;
        while(sum){
            tmp += sum % 10;
            sum /= 10;
        }
        count++;
        sum = tmp;
    }
    printf("%d\n", count);
    if(sum % 3 == 0) printf("YES");
    else printf("NO");
    return 0;
}
