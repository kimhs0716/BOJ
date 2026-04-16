#include <stdio.h>
#include <cmath>

int M = 0;
int arr[8];

void dfs(int depth, int n, int *tarr);
int sum(int *tarr, int n);
bool include(int *tarr, int n, int s);

int main(){
    int tarr[8];
    for(int i = 0; i < 8; i++)
        tarr[i] = -1;

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    dfs(0, n, tarr);

    printf("%d\n", M);

    return 0;
}

void dfs(int depth, int n, int *tarr){
    if(depth == n){
        int S = sum(tarr, n);
        M = M > S ? M : S;
        return;
    }
    for(int i = 0; i < n; i++){
        if(include(tarr, i, depth)) continue;
        tarr[depth] = i;
        dfs(depth + 1, n, tarr);
    }
    tarr[depth] = -1;
}

int sum(int *tarr, int n){
    int res = 0;
    for(int i = 0; i < n - 1; i++){
        res += abs(arr[tarr[i]] - arr[tarr[i + 1]]);
    }
    return res;
}

bool include(int *tarr, int n, int s){
    for(int i = 0; i < s; i++)
        if(tarr[i] == n) return true;
    return false;
}
