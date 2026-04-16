#include <stdio.h>
int max(int a, int b){
    return (a > b) ? a : b;
}
int min(int a, int b){
    return (a < b) ? a : b;
}
int main(){
    int n;
    scanf("%d", &n);
    int preM[3];
    int prem[3];
    int M[3];
    int m[3];
    int temp[3];
    scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
    M[0] = m[0] = preM[0] = prem[0] = temp[0];
    M[1] = m[1] = preM[1] = prem[1] = temp[1];
    M[2] = m[2] = preM[2] = prem[2] = temp[2];
    n--;
    while(n--){
        scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
        M[0] = max(preM[0], preM[1]) + temp[0];
        M[1] = max(preM[0], max(preM[1], preM[2])) + temp[1];
        M[2] = max(preM[1], preM[2]) + temp[2];
        m[0] = min(prem[0], prem[1]) + temp[0];
        m[1] = min(prem[0], min(prem[1], prem[2])) + temp[1];
        m[2] = min(prem[1], prem[2]) + temp[2];
        preM[0] = M[0];
        preM[1] = M[1];
        preM[2] = M[2];
        prem[0] = m[0];
        prem[1] = m[1];
        prem[2] = m[2];
    }
    printf("%d %d\n", max(M[0], max(M[1], M[2])), min(m[0], min(m[1], m[2])));
    return 0;
}
