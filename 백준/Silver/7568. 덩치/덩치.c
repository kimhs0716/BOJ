#include <stdio.h>
int bigger(int *n, int *m){
    if(n[0] > m[0] && n[1] > m[1]) return 1;
    return 0;
}
int main() {
    int d[50][2];
    int res[50] = {0, };
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &d[i][0], &d[i][1]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(bigger(d[j], d[i])) res[i]++;
        }
    for(int i = 0; i < n; i++) printf("%d ", res[i] + 1);
    return 0;
}
