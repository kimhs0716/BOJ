#include <stdio.h>
#include <math.h>

int main(){
    int t, x, y, r;
    scanf("%d", &t);
    for(int asdf = 0; asdf < t; asdf++){
        scanf("%d %d", &x, &y);
        y -= x;
        x = 0;
        int count = 0;
        r = 1;
        while(y / 2 >= r) {
            y -= r * 2;
            count += 2;
            r++;
        }

        if (1 <= y && y <= r)
            count++;
        else if (r < y)
            count += 2;

        printf("%d\n", count);
    }
    return 0;
}
