#include <iostream>
using namespace std;
int main(){
    int a, b, c, d, e, f, g, h, i;
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d:%d:%d", &d, &e, &f);
    i = f - c;
    if(i < 0){
        i += 60;
        e--;
    }
    h = e - b;
    if(h < 0){
        h += 60;
        d--;
    }
    g = d - a;
    if(g < 0){
        g += 24;
    }
    printf("%02d:%02d:%02d\n", g, h, i);
    return 0;
}
