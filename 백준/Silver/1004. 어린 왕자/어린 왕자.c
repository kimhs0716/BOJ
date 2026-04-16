#include <stdio.h>
int isin(int px, int py, int cx, int cy, int r){
    if((px - cx) * (px - cx) + (py - cy) * (py - cy) < r * r) return 1;
    return 0;
}
int main() {
    int n, count, sx, sy, dx, dy, cx, cy, r, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        count = 0;
        scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d %d %d", &cx, &cy, &r);
            if(isin(sx, sy, cx, cy, r) != isin(dx, dy, cx, cy, r)) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
