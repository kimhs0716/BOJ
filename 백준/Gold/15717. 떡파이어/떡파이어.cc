#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long int lld;
lld pow(lld a, lld b);
int main(){
    lld n;
    cin >> n;
    if(n == 0){
        cout << 1 << endl;
        return 0;
    }
    cout << pow(2L, n - 1) << endl;
    return 0;
}
lld pow(lld a, lld b){
    if(b == 0) return 1;
    lld ret = pow(a, b / 2) % mod;
    ret = (ret * ret) % mod;
    if(b & 1)
        ret = (ret * a) % mod;
    return ret;
}
