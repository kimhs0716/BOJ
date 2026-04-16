#include <stdio.h>
#include <math.h>
int main() {
    int arr[100000] = {0, };
    int n, c = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int i = 0, j = n - 1, s, m = 2000000001;
    int x, y;
    while(i != j){
        s = arr[i] + arr[j];
        if(abs(s) < m){
            m = abs(s);
            x = i;
            y = j;
        }
        if(s < 0) i++;
        else j--;
    }
    printf("%d", arr[x] + arr[y]);
    return 0;
}
