#include <iostream>
#define mod 1000000007
typedef long long int lld;
typedef struct {
    lld arr[2][2];
} mat22;
mat22 pow(mat22 m, lld n);
mat22 mul(mat22 m1, mat22 m2);
using namespace std;
int main(){
    lld n;
    mat22 a1 = {11, 3, 3, 0};
    mat22 f = {4, 1, -1, 0};
    cin >> n;
    if(n & 1){
        cout << 0 << endl;
        return 0;
    }
    n /= 2;
    mat22 res = mul(a1, pow(f, n - 1));
    cout << res.arr[0][1] << endl;
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
