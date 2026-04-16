#include <stdio.h>
void rotate(int arr[][2]){
    int t = arr[0][1];
    arr[0][1] = arr[0][0];
    arr[0][0] = arr[1][0];
    arr[1][0] = arr[1][1];
    arr[1][1] = t;
}
int main(){
    int arr[2][2];
    for(int i = 0; i < 4; i++)
        scanf("%d", &arr[i / 2][i % 2]);
    double m = 0;
    int c;
    for(int i = 0; i < 4; i++){
        double val = (double)arr[0][0] / arr[1][0] + (double)arr[0][1] / arr[1][1];
        if(m < val){
            m = val;
            c = i;
        }
        rotate(arr);
    }
    printf("%d", c);
}
