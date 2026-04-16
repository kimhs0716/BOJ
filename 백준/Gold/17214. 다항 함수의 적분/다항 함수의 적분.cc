#include <stdio.h>
using namespace std;
int main(){
    int a;
    scanf("%d", &a);
    char ch;
    if(scanf(" %c", &ch) == EOF){
        if(a == 0) printf("W\n");
        else if(a == 1) printf("x+W\n");
        else if(a == -1) printf("-x+W\n");
        else printf("%dx+W\n", a);
        return 0;
    }
    if(scanf(" %c", &ch) == EOF){
        if(a == 2) printf("xx+W\n");
        else if (a == -2) printf("-xx+W\n");
        else printf("%dxx+W\n", a / 2);
        return 0;
    }
    int b;
    scanf("%d", &b);
    if(ch == '-') b *= -1;
    if(a == 2) {
        if (b == 1) printf("xx+x+W\n");
        else if(b == -1) printf("xx-x+W\n");
        else if(b == 0) printf("xx+W\n");
        else if(b < 0) printf("xx-%dx+W\n", -b);
        else printf("xx+%dx+W\n", b);
    }
    else if(a == -2){
        if (b == 1) printf("-xx+x+W\n");
        else if(b == -1) printf("-xx-x+W\n");
        else if(b == 0) printf("-xx+W\n");
        else if(b < 0) printf("-xx-%dx+W\n", -b);
        else printf("-xx+%dx+W\n", b);
    }
    else{
        if (b == 1) printf("%dxx+x+W\n", a / 2);
        else if(b == -1) printf("%dxx-x+W\n", a / 2);
        else if(b == 0) printf("%dxx+W\n", a / 2);
        else if(b < 0) printf("%dxx-%dx+W\n", a / 2, -b);
        else printf("%dxx+%dx+W\n", a / 2, b);
    }
    return 0;
}
