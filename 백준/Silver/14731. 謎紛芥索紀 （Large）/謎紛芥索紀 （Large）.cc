#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long int lld;
lld pow(lld a, lld b);
int main(){
    lld n;
    cin >> n;
    lld c, k;
    lld s = 0;
    while(n--){
        scanf("%lld %lld", &c, &k);
        if(k == 0) continue;
        s += (pow(2L, k - 1) * ((k * c) % mod)) % mod;
        s %= mod;
    }
    cout << s << endl;
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
