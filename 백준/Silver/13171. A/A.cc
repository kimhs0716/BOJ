#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long int lld;
lld pow(lld a, lld b);
int main(){
    lld a, b;
    cin >> a >> b;
    a %= mod;
    a = pow(a, b);
    cout << a << endl;
    return 0;
}
lld pow(lld a, lld b){
    if(b == 1) return a;
    lld ret = pow(a, b / 2) % mod;
    ret = (ret * ret) % mod;
    if(b & 1)
        ret = (ret * a) % mod;
    return ret;
}
