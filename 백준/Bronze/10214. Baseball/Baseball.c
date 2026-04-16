#include <stdio.h>
int main() {
    int n, a, b, s1, s2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        s1 = s2 = 0;
        for(int j = 0; j < 9; j++){
            scanf("%d %d", &a, &b);
            s1 += a;
            s2 += b;
        }
        if(s1 < s2) printf("Korea\n");
        else if(s1 > s2) printf("Yonsei\n");
        else printf("Draw\n");
    }
    return 0;
}
