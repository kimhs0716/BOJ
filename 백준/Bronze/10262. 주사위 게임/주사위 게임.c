#include <stdio.h>
int main() {
    int a, b;
    double arr[4];
    for(int i = 0; i < 4; i++){
        scanf("%d %d", &a, &b);
        arr[i] = (double)(a + b) / 2;
    }
    if(arr[0] + arr[1] > arr[2] + arr[3]){
        printf("Gunnar");
    }
    else if(arr[0] + arr[1] < arr[2] + arr[3])
        printf("Emma");
    else printf("Tie");
    return 0;
}
