#include <stdio.h>
#include <stdlib.h>
int main() {
    int a[6], bessie, daisy;
    for(int i = 0; i < 6; i++)
        scanf("%d", &a[i]);
    bessie = (abs(a[0] - a[4]) > abs(a[1] - a[5])) ? abs(a[0] - a[4]) : abs(a[1] - a[5]);
    daisy = abs(a[2] - a[4]) + abs(a[3] - a[5]);
    if(bessie < daisy) printf("bessie");
    else if(bessie == daisy) printf("tie");
    else printf("daisy");
    return 0;
}
