#include <stdio.h>
int main(){
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        printf("Pairs for %d:", n);
        int c = 0;
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(j + k == n){
                    if(c != 0) printf(",");
                    printf(" %d %d", j, k);
                    c++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
