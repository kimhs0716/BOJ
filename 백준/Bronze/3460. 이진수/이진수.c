#include <stdio.h>
int main() {
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        int j = 0;
        while(a){
            if(a % 2 == 1) printf("%d ", j);
            a /= 2;
            j++;
        }
        printf("\n");
    }
    return 0;
}
