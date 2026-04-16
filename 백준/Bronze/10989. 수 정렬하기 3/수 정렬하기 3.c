#include <stdio.h>
int main(){
    int n, t;
    int count[10000] = {0, };
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        count[t - 1]++;
    }
    for(int i = 1; i < 10001; i++)
        for(int j = 0; j < count[i - 1]; j++)
            printf("%d\n", i);
    return 0;
}
