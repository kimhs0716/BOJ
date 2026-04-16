#include <stdio.h>
int main() {
    int a[10], b[10], s1 = 0, s2 = 0, w = 2;
    char res[3] = {'A', 'B', 'D'};
    for(int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < 10; i++)
        scanf("%d", &b[i]);
    for(int i = 0; i < 10; i++){
        if(a[i] < b[i]){
            s2 += 3;
            w = 1;
        }
        else if(a[i] > b[i]){
            s1 += 3;
            w = 0;
        }
        else{
            s1++;
            s2++;
        }
    }
    (s1 < s2) && (w = 1);
    (s1 > s2) && (w = 0);
    printf("%d %d\n%c", s1, s2, res[w]);

    return 0;
}
