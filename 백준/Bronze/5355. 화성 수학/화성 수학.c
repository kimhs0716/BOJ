#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    while(a--){
        double n;
        scanf("%lf", &n);
        char arr[10];
        scanf("%[^\n]s", arr);
        int i = 0;
        while(arr[i]){
            if(arr[i] == ' '){
                i++;
                continue;
            }
            if(arr[i] == '@') n *= 3;
            if(arr[i] == '%') n += 5;
            if(arr[i] == '#') n -= 7;
            i++;
        }
        printf("%.2lf\n", n);
    }
    return 0;
}
