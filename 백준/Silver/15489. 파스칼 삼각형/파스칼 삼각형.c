#include <stdio.h>
int arr[30][30];
int main(){
    int r, c, w;
    scanf("%d %d %d", &r, &c, &w);
    for(int i = 0; i < r + w - 1; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) arr[i][j] = 1;
            else arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    int s = 0;
    for(int i = r - 1; i < r + w - 1; i++)
        for(int j = c - 1; j < c - r + i + 1; j++){
            s += arr[i][j];
        }
    printf("%d", s);
    return 0;
}
