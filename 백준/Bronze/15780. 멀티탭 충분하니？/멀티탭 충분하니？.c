#include <stdio.h>
int main(){
    int n, k, s = 0, a;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &a);
        s += (a + 1) / 2;
    }
    if(s < n) printf("NO");
    else printf("YES");
    return 0;
}
