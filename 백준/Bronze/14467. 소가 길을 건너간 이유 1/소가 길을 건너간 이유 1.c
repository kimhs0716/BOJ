#include <stdio.h>
int main(){
    int arr[10];
    for(int i = 0; i < 10; i++)
        arr[i] = -1;
    int n;
    scanf("%d", &n);
    int count = 0;
    while(n--){
        int idx, val;
        scanf("%d %d", &idx, &val);
        idx--;
        if(arr[idx] == -1){
            arr[idx] = val;
            continue;
        }
        if(arr[idx] != val){
            count++;
            arr[idx] = val;
        }
    }
    printf("%d\n", count);
    return 0;
}
