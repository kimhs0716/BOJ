#include <iostream>
using namespace std;
typedef long long int lld;
bool isprime(lld n);
lld pow(lld a, lld b, lld c);
int main(){
    while(1){
        int p, a;
        cin >> p >> a;
        if(p == 0) break;
        if(pow(a, p, p) == a && !isprime(p)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
lld pow(lld a, lld b, lld c){
    if(b == 0) return 1;
    lld div = pow(a, b / 2, c);
    lld ret = (div * div) % c;
    if(b % 2) ret = (ret * (a % c)) % c;
    return ret;
}
bool isprime(lld n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int i = 3;
    while(i * i <= n){
        if(n % i == 0) return false;
        i += 2;
    }
    return true;
}
