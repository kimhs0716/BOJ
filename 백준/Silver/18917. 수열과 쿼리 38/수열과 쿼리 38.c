#include <stdio.h>
int main(){
    long long int sum = 0;
    long long int xor = 0;
    int n;
    scanf("%d", &n);
    while(n--){
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1){
            int data;
            scanf("%d", &data);
            sum += data;
            xor ^= data;
        }
        else if(cmd == 2){
            int data;
            scanf("%d", &data);
            sum -= data;
            xor ^= data;
        }
        else if(cmd == 3)
            printf("%lld\n", sum);
        else printf("%lld\n", xor);
    }
    return 0;
}
