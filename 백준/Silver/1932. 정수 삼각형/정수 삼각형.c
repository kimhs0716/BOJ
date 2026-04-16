#include <stdio.h>
int max(int a, int b){
    return (a > b) ? a : b;
}
int dp(int tri[][500], int cache[][500], int i, int j){
    if(cache[i][j] == -1){
        cache[i][j] = max((j == 0) ? 0 : dp(tri, cache, i - 1, j - 1), (i == j) ? 0 : dp(tri, cache, i - 1, j)) + tri[i][j];
    }
    return cache[i][j];
}
int main(){
    int size;
    scanf("%d", &size);
    int tri[500][500], cache[500][500];
    for(int i = 0; i < size; i++)
        for(int j = 0; j <= i; j++){
            scanf("%d", &tri[i][j]);
            cache[i][j] = -1;
        }
    cache[0][0] = tri[0][0];
    int max_val = -1;
    for(int i = 0; i < size; i++)
        max_val = max(max_val, dp(tri, cache, size - 1, i));
    printf("%d\n", max_val);
    return 0;
}
