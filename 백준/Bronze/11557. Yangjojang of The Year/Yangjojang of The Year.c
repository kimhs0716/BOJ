#include <stdio.h>
int main() {
    int t, n, y, m;
    char name[21], max[21];
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        m = 0;
        for(int j = 0; j < n; j++){
            scanf("%s", name);
            scanf("%d", &y);
            if(y > m){
                m = y;
                strcpy(max, name);
            }
        }
        printf("%s\n", max);
    }
    return 0;
}
