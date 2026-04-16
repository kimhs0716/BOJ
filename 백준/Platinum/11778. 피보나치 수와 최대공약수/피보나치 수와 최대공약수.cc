#include <iostream>
#define mod 1000000007
typedef long long int lld;
typedef struct {
    lld arr[2][2];
} mat22;
mat22 pow(mat22 m, lld n);
mat22 mul(mat22 m1, mat22 m2);
lld gcd(lld a, lld b);
using namespace std;
int main(){
    lld n, m;
    cin >> n >> m;
    lld g = gcd(n, m);
    mat22 f = {1, 1, 1, 0};
    mat22 res = pow(f, g);
    cout << res.arr[0][1] << endl;
    return 0;
}
lld gcd(lld a, lld b){
    lld r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
mat22 pow(mat22 m, lld n){
    if(n == 1) return m;
    mat22 ret = pow(m, n / 2);
    ret = mul(ret, ret);
    if(n & 1)
        ret = mul(ret, m);
    return ret;
}
mat22 mul(mat22 m1, mat22 m2){
    mat22 ret;
    ret.arr[0][0] = ((m1.arr[0][0] * m2.arr[0][0]) % mod + (m1.arr[0][1] * m2.arr[1][0]) % mod) % mod;
    ret.arr[0][1] = ((m1.arr[0][0] * m2.arr[0][1]) % mod + (m1.arr[0][1] * m2.arr[1][1]) % mod) % mod;
    ret.arr[1][0] = ((m1.arr[1][0] * m2.arr[0][0]) % mod + (m1.arr[1][1] * m2.arr[1][0]) % mod) % mod;
    ret.arr[1][1] = ((m1.arr[1][0] * m2.arr[0][1]) % mod + (m1.arr[1][1] * m2.arr[1][1]) % mod) % mod;
    return ret;
}
