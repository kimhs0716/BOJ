#include <iostream>
#define mod 100
typedef long long int lld;
typedef struct {
    lld arr[2][2];
} mat22;
mat22 pow(mat22 m, lld n);
mat22 mul(mat22 m1, mat22 m2);
using namespace std;
int main(){
    int x, y, a0, a1, n;
    cin >> x >> y >> a0 >> a1 >> n;
    mat22 A1 = {a1, a0, a0, 0};
    mat22 rec = {x, 1, y, 0};
    mat22 res = mul(A1, pow(rec, n));
    printf("%02d\n", res.arr[0][1]);
    return 0;
}
mat22 pow(mat22 m, lld n){
    if(n == 0) return {1, 0, 0, 1};
    mat22 ret = pow(m, n / 2);
    ret = mul(ret, ret);
    if(n & 1)
        ret = mul(ret, m);
    return ret;
}
mat22 mul(mat22 m1, mat22 m2){
    mat22 ret;
    ret.arr[0][0] = ((m1.arr[0][0] * m2.arr[0][0]) % mod + (m1.arr[0][1] * m2.arr[1][0]) % mod + mod) % mod;
    ret.arr[0][1] = ((m1.arr[0][0] * m2.arr[0][1]) % mod + (m1.arr[0][1] * m2.arr[1][1]) % mod + mod) % mod;
    ret.arr[1][0] = ((m1.arr[1][0] * m2.arr[0][0]) % mod + (m1.arr[1][1] * m2.arr[1][0]) % mod + mod) % mod;
    ret.arr[1][1] = ((m1.arr[1][0] * m2.arr[0][1]) % mod + (m1.arr[1][1] * m2.arr[1][1]) % mod + mod) % mod;
    return ret;
}
